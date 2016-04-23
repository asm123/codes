import matplotlib.pyplot as plt
import numpy as np

input_file = "/home/asmita/study/datasets/islr/Advertising.csv"

data = np.genfromtxt(input_file, delimiter=',', dtype='float', usecols=(1, 2, 3, 4), names=['TV', 'Radio', 'Newspaper', 'Sales'])

plt.subplot(3, 1, 1)
plt.plot(data['TV'], data['Sales'], 'ro')
plt.xlabel('TV')
plt.ylabel('Sales')
plt.subplot(3, 1, 2)
plt.plot(data['Radio'], data['Sales'], 'ro')
plt.xlabel('Radio')
plt.ylabel('Sales')
plt.subplot(3, 1, 3)
plt.plot(data['Newspaper'], data['Sales'], 'ro')
plt.xlabel('Newspaper')
plt.ylabel('Sales')

plt.show()