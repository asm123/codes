from heap import Heap

"""
Author: Asmita
An implementatio of priority queue data structure
"""

class PriorityQueue:
	def __init__(self, array=[]):
		self.heap = Heap(array)

	def get_max(self):
		if not self.heap.array:
			return None
		return self.heap.array[0]

	def extract_max(self):
		if not self.heap.array:
			return None
		maximum = self.heap.array[0]
		self.heap.array[0] = self.heap.array[-1]
		del self.heap.array[-1]
		self.heap.size = len(self.heap.array)
		self.heap.max_heapify(0)
		return maximum

	def increase_key(self, i, key):
		if key < self.heap.array[i]:
			raise Exception('Error:', 'New key is smaller than the current key.')
		self.heap.array[i] = key
		while i > 0 and self.heap.array[i] > self.heap.array[self.heap.parent(i)]:
			self.heap.array[i], self.heap.array[self.heap.parent(i)] = self.heap.array[self.heap.parent(i)], self.heap.array[i]
			i = self.heap.parent(i)

	def insert(self, key):
		if not self.heap.array:
			self.heap.array.append(key)
		else:
			self.heap.array.append(key-1)
			self.heap.size = len(self.heap.array)
			self.increase_key(self.heap.size-1, key)

	def print_priority_queue(self):
		print self.heap.array


if __name__ == '__main__':
	pq = PriorityQueue()
	pq.insert(2)
	pq.insert(12)
	pq.insert(3)
	pq.insert(10)
	print pq.get_max()
	print pq.extract_max()
	pq.print_priority_queue()
	pq.insert(0)
	pq.increase_key(3, 1000)
	pq.print_priority_queue()






