// contribute by - HARSH AGARWAL <harsh5nov11@gmail.com>

/*
Input Format:
The first line contains an integer 'q' which denotes the number of queries to be run against each operation in the stack. 
Then the test cases follow.
Every 'q' lines represent an operation that needs to be performed.
For the push operation, the input line will contain two integers separated by a single space, representing the type of the operation in integer and the integer data being pushed into the stack.
For the rest of the operations on the stack, the input line will contain only one integer value, representing the query being performed on the stack.


Query-1(Denoted by an integer 1): Pushes an integer data to the stack.
Query-2(Denoted by an integer 2): Pops the data kept at the top of the stack and returns it to the caller.
Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the top of the stack but doesn't remove it, unlike the pop function.
Query-4(Denoted by an integer 4): Returns the current size of the stack.
Query-5(Denoted by an integer 5): Returns a boolean value denoting whether the stack is empty or not.
  */

#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};


class Stack {
	// Define the data members
    Node *head;
    int size;
   public:
    Stack() {
        
        head=NULL;
        size=0;
        // Implement the Constructor
    }

	/*----------------- Public Functions of Stack -----------------*/


    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return size==0;
    }

    void push(int element) {
        
        Node *nhead= new Node(element);
        nhead->next= head;
        head= nhead;
        size++;
    }

    int pop() {
        // Implement the pop() function
        if(size>0)
            {
             int z= head->data;
            Node *tmp= head;
        head=head->next;
            delete tmp;
        size--;
        return z;
        }
        return -1;
       
    }

    int top() {
        // Implement the top() function
         if(size>0)
            {
         int z= head->data;
        return z;
         }
        return -1;
    }
};

int main() {
    Stack st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}
