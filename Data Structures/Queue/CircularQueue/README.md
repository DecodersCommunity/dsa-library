
# Circular Queue


Circular Queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called “Ring Buffer”.

### Why Circular Queues?
Once the queue becomes full, we can not insert more elements. Even though we dequeue  few of the elements.

### Operations on circular queue :
* front : Get the front item from the queue.
* rear : Get the last item from the queue.
* enQueue() : This function is used to enqueue the element into the circular queue. New element will be added at the rear end of the queue.
* deQueue() : This function is used to delete the element from the circular queue. Delete operation is done from the front end of the queue.
<p align="center">
<img src="https://user-images.githubusercontent.com/77777064/193612226-0f6d9821-3b4e-44e9-8ec1-c9d6d2ca07f2.png" width="700px" >
</p>
