// Contributed by - Shlok Kumar Suman <shloksuman01@gmail.com>

#include <bits/stdc++.h>
using namespace std;

struct Queue
{

    // Initialize front and rear
    int rear, front;

    // Circular Queue
    int size;

    int *arr;

    Queue(int s)
    {

        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void enQueue(int value);

    int deQueue();

    void displayQueue();
};

/* Function to create Circular queue */
void Queue::enQueue(int value)
{
    if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
    {
        cout << "\nQueue is Full";
        return;
    }

    else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        arr[rear] = value;
    }

    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }

    else
    {
        rear++;
        arr[rear] = value;
    }
}

// Function to delete element from Circular Queue
int Queue::deQueue()
{
    if (front == -1)
    {
        cout << "\nQueue is Empty";
        return INT_MIN;
    }

    int data = arr[front];
    arr[front] = -1;

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }

    else if (front == size - 1)
        front = 0;

    else
        front++;

    return data;
}

// Function displaying the elements
// of Circular Queue
void Queue::displayQueue()
{
    if (front == -1)
    {
        cout << "\nQueue is Empty";
        return;
    }

    cout << "\nElements in Circular Queue are: ";

    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
    }

    else
    {
        for (int i = front; i < size; i++)
            cout << arr[i] << " ";

        for (int i = 0; i <= rear; i++)
            cout << arr[i] << " ";
    }
}

int main()
{
    Queue q(5);

    // Inserting elements in Circular Queue
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);

    // Display elements present in Circular Queue
    q.displayQueue();

    // Deleting elements from Circular Queue
    cout << "\nDeleted value = " << q.deQueue();
    cout << "\nDeleted value = " << q.deQueue();

    q.displayQueue();

    q.enQueue(50);
    q.enQueue(60);
    q.enQueue(70);

    q.displayQueue();

    return 0;
}

// OUTPUT:

// Elements in circular queue are : 10 20 30 40

// Deleted element = 10

// Deleted element =20

// Elements in circular queue are : 30 40

// Elements in circular queue are : 30 40 50 60 70
