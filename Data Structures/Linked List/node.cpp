//Contributed By- Shashank Rai(shashank.rai00331@gmail.com)

// defining a class Node for a single node for linked list
#include <climits>
class Node {
    public:

    int data;
    Node *next;   // --
    // this pointer is node datatype because it is basically a pointer that stores the address of the next node so it is pointer with datatype as Node because it has to store the address of next node which has datatype as Node .      

    // defining the constructor 

    Node(int data){       // USER HAS TO PASS THE DATA 
        this -> data = data;
        next = NULL;
    }
};