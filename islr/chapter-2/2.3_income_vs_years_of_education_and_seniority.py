import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

input_file = "/home/asmita/study/datasets/islr/Income2.csv"

data = np.genfromtxt(input_file, delimiter=',', dtype='float', usecols=(1, 2, 3), names=['Education', 'Seniority', 'Income'])

fig = plt.figure()
ax = fig.gca(projection='3d')

ax.set_title('Income vs. years of education and seniority')
ax.set_xlabel('Education')
ax.set_ylabel('Seniority')
ax.set_zlabel('Income')

ax.scatter(data['Education'], data['Seniority'], data['Income'], 
	color='red',
	marker='o',
	s=30)
			
plt.show()
