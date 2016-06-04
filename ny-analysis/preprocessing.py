from os import listdir
from os.path import import isfile, join
from cleaning import clean_data

class Preprocessor:
	def __init__(self, input_file, output_dir):
		self.input_file = input_file
		self.output_dir = output_dir

	def clean_data(self):
		file_name = os.path.basename(self.input_file)
		cleaning.clean_data(input_file, join(output_dir, 'cleaned_' + file_name))

	def divide_trips_into_days(self, input_file, output_dir):
		file_name = os.path.splittext(input_file)[0]
		year_month = file_name.split('_')[-1]
		year = int(year_month.split('-')[0])
		month = int(year_month.split('-')[1])

		# create a directories for year and months
		year_directory_path = join(output_dir, str(year))
		month_directory_path = join(year_directory_path, str(month))
		if not os.path.exists(year_directory_path):
			os.makedirs(year_directory_path)
		if not os.path.exists(month_directory_path):
			os.makedirs(month_directory_path)

		# per day requests
		per_day_requests = dict()

		with open(input_file) as f:
			for line in f:
				line = line.strip()
				if not line:
					continue
				fields = line.split(',')
				



	def preprocess(self):
		
