# original bounds
min_lat, min_lon = 40.4774, -74.2591
max_lat, max_lon = 40.9176, -73.7003

data_year, data_month, max_days = 2015, 1, 31

def is_within_bounds(lat, lon):
	global min_lat, min_lon, max_lat, max_lon
	return (lat >= min_lat and lat <= max_lat and lon >= min_lon and lon <= max_lon)

def is_valid_datetime(time_string):
	global data_year, data_month, max_days
	try:
		fields = time_string.strip().split()
		date_part = fields[0]
		time_part = fields[1]

		fields = date_part.split('-')
		year = int(fields[0])
		month = int(fields[1])
		day = int(fields[2])

		if year != data_year or data_month != month or day < 0 or day > max_days:
			return False

		fields = time_part.strip().split(":")
		hour = int(fields[0])
		minute = int(fields[1])
		second = int(fields[2])

		if hour < 0 or hour > 23 or minute < 0 or minute > 59 or second < 0 or second > 59:
			return False
		return True
	except:
		return False

def clean_data(input_file_path, output_file_path):
	"""
	Reads requests from input file, performs bounds and date validations and writes the clean requests to output file
	"""
	global min_lat, min_lon, max_lat, max_lon
	
	clean_requests = []

	# reading input file
	print "Reading all requests..."
	count = -1
	with open(input_file_path) as f:
		for line in f:
			count += 1
			if count == 0:
				# adding header
				clean_requests.append("trip_id," + line)
				continue
			line = line.strip()
			if not line:
				continue
			fields = line.split(",")
			try:
				pickup_lon, pickup_lat = float(fields[5]), float(fields[6])
				dropoff_lon, dropoff_lat = float(fields[9]), float(fields[10])
				if not (is_within_bounds(pickup_lat, pickup_lon) and is_within_bounds(dropoff_lat, dropoff_lon)):
					continue
				pickup_time = fields[1]
				dropoff_time = fields[2]
				if not (is_valid_datetime(pickup_time) and is_valid_datetime(dropoff_time)):
					continue
				clean_requests.append(str(count) + "," + line)
			except:
				continue
				# break

	print "Total requests:", count
	print "Clean requests:", len(clean_requests)
	# writing out clean requests
	print "Writing out clean requests..."
	with open(output_file_path, 'w') as f:
		for line in clean_requests:
			line = line.strip()
			if not line:
				continue
			f.write(line + "\n")