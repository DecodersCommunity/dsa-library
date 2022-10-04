## Heap Data Structure

Heap has two type
1. Min heap
2. Max heap

1. Min heap= Root node is smallest node in the entire tree
                                      3
                                    /   \
                                   7     4
                                  / \    / \
                                 8   11 6    9
                            
so what happen in it is when you insert any number in it add it on leaf, after that it do Heapify.
it compare it with the root node if it is smaller than the root node then it will swap it.

when you want to remove, so what happen is it remove the root element, after that it do downheapify
 in downheapify what happen is 3 is remove and 8 will come at that place. and then check 7 and 4 if 7 and 4
 is less than 8 then 8 will swap with 4 and it will happen until it placed in correct order.

 