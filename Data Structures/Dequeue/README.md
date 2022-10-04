## DeQueue Data Structure

Deque or Double Ended Queue is a generalized version of Queue data structure that allows insert and delete at both ends.

### Operations on Deque: Mainly the following four basic operations are performed on queue:
* **insertFront()**: Adds an item at the front of Deque.
* **insertLast()**: Adds an item at the rear of Deque.
* **deleteFront()**: Deletes an item from the front of Deque.
* **deleteLast()**: Deletes an item from the rear of Deque. In addition to the above operations, the following operations are also supported.
* **getFront()**: Gets the front item from the queue.
* **getRear()**: Gets the last item from queue.
* **isEmpty()**: Checks whether Deque is empty or not.
* **isFull()**: Checks whether Deque is full or not.

**Applications of Deque**: Since Deque supports both stack and queue operations, it can be used as both. The Deque data structure supports clockwise and anticlockwise rotations in O(1) time which can be useful in certain applications. Also, the problems where elements need to be removed and or added to both ends can be efficiently solved using Deque. For example see the Maximum of all subarrays of size k problem., 0-1 BFS, and Find the first circular tour that visits all petrol pumps. See the wiki page for another example of the A-Steal job scheduling algorithm where Deque is used as deletions operation is required at both ends. 

### Some Practical Applications of Deque:

* Applied as both stack and queue, as it supports both operations.
* Storing a web browser’s history.
* Storing a software application’s list of undo operations.
* Job scheduling algorithm