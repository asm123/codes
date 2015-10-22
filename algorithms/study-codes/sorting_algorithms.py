from heap import Heap

def heap_sort(array):
	h = Heap(array)
	i = h.size - 1
	while i >= 1:
		h.array[0], h.array[i] = h.array[i], h.array[0]
		h.size -= 1
		h.max_heapify(0)
		i -= 1

if __name__ == '__main__':
	array = [4, 1, 3, 2, 16, 9, 10, 14, 8, 7]
	heap_sort(array)
	print array
	