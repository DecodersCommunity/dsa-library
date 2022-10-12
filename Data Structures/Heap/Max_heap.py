# Contributed by - Rishav Upraity <rishavupraity9@protonmail.com>
import sys
 
#defining a class max_heap for the heap data structure
 
class max_heap: 
    def __init__(self, sizelimit):
        self.sizelimit = sizelimit
        self.cur_size = 0
        self.Heap = [0]*(self.sizelimit + 1)
        self.Heap[0] = sys.maxsize
        self.root = 1
 
 
    # helper function to swap the two given nodes of the heap
    # this function will be needed for max-heapify and insertion 
    # in order to swap nodes which are not in order (not satisfy max-heap property)
    def swapnodes(self, node1, node2):
        self.Heap[node1], self.Heap[node2] = self.Heap[node2], self.Heap[node1]
  
    # THE MAX_HEAPIFY FUNCTION
    def max_heapify(self, i):
  
        # If the node is a not a leaf node and is lesser than any of its child
        if not (i >= (self.cur_size//2) and i <= self.cur_size):
            if (self.Heap[i] < self.Heap[2 * i]  or  self.Heap[i] < self.Heap[(2 * i) + 1]): 
                if self.Heap[2 * i] > self.Heap[(2 * i) + 1]:
     # Swap the node with the left child and call the max_heapify function on it
                    self.swapnodes(i, 2 * i)
                    self.max_heapify(2 * i)
  
                else:
                # Swap the node with right child and then call the max_heapify function on it
                    self.swapnodes(i, (2 * i) + 1)
                    self.max_heapify((2 * i) + 1)
  
 
 
    # THE HEAPPUSH FUNCTION
    def heappush(self, element):
        if self.cur_size >= self.sizelimit :
            return
        self.cur_size+= 1
        self.Heap[self.cur_size] = element 
        current = self.cur_size
        while self.Heap[current] > self.Heap[current//2]:
            self.swapnodes(current, current//2)
            current = current//2
  
  
    # THE HEAPPOP FUNCTION
    def heappop(self):
        last = self.Heap[self.root]
        self.Heap[self.root] = self.Heap[self.cur_size]
        self.cur_size -= 1
        self.max_heapify(self.root)
        return last
  
  
    # THE BUILD_HEAP FUNCTION
    def build_heap(self): 
        for i in range(self.cur_size//2, 0, -1):
            self.max_heapify(i)
  
  
    # helper function to print the heap
    def print_heap(self):
        for i in range(1, (self.cur_size//2)+1):
            print("Parent Node is "+ str(self.Heap[i])+" Left Child is "+ str(self.Heap[2 * i]) +                  " Right Child is "+ str(self.Heap[2 * i + 1]))
  
  
 
maxHeap = max_heap(10)
maxHeap.heappush(15)
maxHeap.heappush(7)
maxHeap.heappush(9)
maxHeap.heappush(4)
maxHeap.heappush(13)
maxHeap.print_heap()