import math

"""
Author: Asmita
An implementation of heap data structure
"""

class Heap:
	def __init__(self, array):
		self.array = array
		self.size = len(array)
		self.build_max_heap()

	def left(self, i):
		return 2*i + 1

	def right(self, i):
		return 2*i + 2

	def parent(self, i):
		return i/2

	def max_heapify(self, i):
		l = self.left(i)
		r = self.right(i)
		largest = i
		if l < self.size and self.array[l] > self.array[i]:
			largest = l
		if r < self.size and self.array[r] > self.array[largest]:
			largest = r
		if largest != i:
			self.array[largest], self.array[i] = self.array[i], self.array[largest]
			self.max_heapify(largest)

	def build_max_heap(self):
		i = (self.size-1) / 2
		while i >= 0:
			self.max_heapify(i)
			i -= 1

	def print_heap(self):
		print self.array

if __name__ == '__main__':
	array = [16, 1, 3, 2, 4, 9, 10, 14, 8, 7]
	h = Heap(array)
	h.print_heap()