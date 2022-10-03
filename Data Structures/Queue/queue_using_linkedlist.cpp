// Contributed by - Shlok Kumar Suman <shloksuman01@gmail.com>

#include <iostream>
using namespace std;

struct LinkedListNode // structure of link node
{
    int data;
    LinkedListNode *next;
} *front = NULL, *rear = NULL, *pointer = NULL, *nextpointer = NULL;

void enqueue(int item) // push the value in the queue
{
    nextpointer = new LinkedListNode;
    nextpointer->data = item;
    nextpointer->next = NULL;
    if (front == NULL)
    {
        front = rear = nextpointer;
        rear->next = NULL;
    }
    else
    {
        rear->next = nextpointer;
        rear = nextpointer;
        rear->next = NULL;
    }
}

int dequeue() // remove the value from the queue
{
    int item;
    if (front == NULL)
    {
        cout << "Queue is empty!!\n";
    }
    else
    {
        pointer = front;
        item = pointer->data;
        front = front->next;
        delete (pointer);
        return (item);
    }
}

int main()
{

    int n, counter = 0, x1;
    cout << "Enter the number of values to be pushed into queue:-\n";
    cin >> n;
    cout << "Enqueue the value:-\n";
    while (counter < n)
    {
        cin >> x1;
        enqueue(x1);
        counter++;
    }
    cout << " After Dequeue :-\n";
    while (true)
    {
        if (front != NULL)
            cout << dequeue() << endl;
        else
            break;
    }
}

// SAMPLE OUTPUT

// Enter the number of values to be pushed into the queue:-
// 3
// Enqueue the value:-
// 25
// 50
// 75
// After Dequeue :-
// 25
// 50
// 75
