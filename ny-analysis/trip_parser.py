import datetime

def parse_datetime(date_time_string):
	fields = date_time_string.strip().split()
	date_part = fields[0]
	time_part = fields[1]

	fields = date_part.split('-')
	year = int(fields[0])
	month = int(fields[1])
	day = int(fields[2])

	fields = time_part.strip().split(":")
	hour = int(fields[0])
	minute = int(fields[1])
	second = int(fields[2])

	return datetime.date(year=year, month=month, day=day, hour=hour, minute=minute, second=second)


def parse(line):
	fields = line.split(",")
	trip_id = int(fields[0])
	pickup_lon, pickup_lat = float(fields[6]), float(fields[7])
	dropoff_lon, dropoff_lat = float(fields[10]), float(fields[11])
	pickup_time, dropoff_time = parse_datetime(fields[2]), parse_datetime(fields[3])
	return Trip(trip_id=trip_id, pickup=Location(pickup_lon, pickup_lon), dropoff=Location(dropoff_lat, dropoff_lon), pickup_time=pickup_time, dropoff_time=dropoff_time, payment_method=None)