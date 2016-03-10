from heap import Heap

def heap_sort(array):
	h = Heap(array)
	i = h.size - 1
	while i >= 1:
		h.array[0], h.array[i] = h.array[i], h.array[0]
		h.size -= 1
		h.max_heapify(0)
		i -= 1

def quick_sort(array):
	def partition(array, p, r):
		x = array[r]
		i = p-1
		for j in range(p, r):
			if array[j] <= x:
				i += 1
				array[i], array[j] = array[j], array[i]
		array[r], array[i+1] = array[i+1], array[r]
		return i+1

	def quick_sort_util(array, p, r):
		if p < r:
			q = partition(array, p, r)
			quick_sort_util(array, p, q-1)
			quick_sort_util(array, q+1, r)

	quick_sort_util(array, 0, len(array)-1)

if __name__ == '__main__':
	array = [4, 1, 3, 2, 16, 9, 10, 14, 8, 7]
	# heap_sort(array)
	quick_sort(array)
	print array
	