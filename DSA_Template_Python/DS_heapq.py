import heapq

# Creating a heap
nums = [3, 1, 4, 1, 5, 9, 2, 6]
heapq.heapify(nums)  # Transforms 'nums' into a heap, in-place

# Adding items to the heap
heapq.heappush(nums, 7)  # Adds 7 to the heap

# Removing the smallest item
smallest = heapq.heappop(nums)  # Removes and returns the smallest item

# Accessing the smallest item without removing it
smallest = nums[0]  # The smallest item is always at index 0

# Transforming a list into a heap
someOtherList = [10, 20, 15]
heapq.heapify(someOtherList)  # Converts 'someOtherList' into a heap

# Merging multiple sorted inputs into a single sorted output and returning an iterator
merged = heapq.merge(nums, someOtherList)  # Merges and sorts 'nums' and 'someOtherList'

# Getting the n largest elements from the heap
n_largest = heapq.nlargest(3, nums)  # Returns the three largest numbers

# Getting the n smallest elements from the heap
n_smallest = heapq.nsmallest(3, nums)  # Returns the three smallest numbers

# Max Heap using heapq (by inverting values)
# Note: Python's heapq module is implemented as a min-heap. For max-heap, invert values.
max_heap = [-x for x in [3, 1, 4, 1, 5, 9, 2, 6]]
heapq.heapify(max_heap)  # Max heap is created by negating values

# Adding item to max heap
heapq.heappush(max_heap, -8)  # Add an element (note the negation)

# Removing the largest item (for max heap)
largest = -heapq.heappop(max_heap)  # Remove and return the largest item (note the negation)
