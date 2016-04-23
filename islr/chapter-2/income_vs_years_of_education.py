import matplotlib.pyplot as plt

input_file = "/home/asmita/study/datasets/islr/Income1.csv"

income = []
years_of_education = []

with open(input_file, 'r') as f:
	for line in f:
		line = line.strip()
		if not line:
			continue
		fields = line.split(",")
		try:
			years_of_education.append(float(fields[1].strip()))
			income.append(float(fields[2].strip()))
		except:
			continue
			
plt.plot(years_of_education, income, 'ro')
plt.xlabel('Years of education')
plt.ylabel('Income')
plt.show()
