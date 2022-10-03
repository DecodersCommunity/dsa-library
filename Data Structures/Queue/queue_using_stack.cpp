#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    stack<int> s;
    int size;
    Queue() { size = 0; }
    void Push(int i)
    {
        cout << "Pushing the element : " << i << endl;
        s.push(i);
        size++;
    }
    int pop()
    {
        if (size == 0)
        {
            cout << "The Queue is empty" << endl;
            return 0;
        }
        int a = s.top();
        s.pop();
        if (!s.empty())
        {
            int b = pop();
            s.push(a);
            return b;
        }
        else
        {
            cout << "Popping " << a << endl;
            size--;
        }
        return a;
    }
    void Show()
    {
        if (size == 0)
        {
            cout << "The Queue is empty" << endl;
            return;
        }
        int a = s.top();
        s.pop();
        if (!s.empty())
            Show();
        cout << a << " ";
        s.push(a);
    }
    int front()
    {
        if (size == 0)
        {
            cout << "The Queue is empty" << endl;
        }
        int b, a = s.top();
        s.pop();
        if (!s.empty())
        {
            int b = front();
            s.push(a);
            return b;
        }
        else
            b = a;
        s.push(a);
        return a;
    }
    bool empty()
    {
        return size == 0;
    }
};

int main()
{
    Queue q;
    q.Push(1);
    q.Push(5);
    q.Push(2);
    q.Push(11);
    q.Show();
    cout << endl;
    cout << "The front most value right now is : " << q.front() << endl;
    q.pop();
    q.pop();
    q.Push(12);
    q.Push(8);
    cout << "The front most value right now is : " << q.front() << endl;
    q.Show();
    cout << endl;
}

// OUTPUT BELOW : 

// Pushing the element : 1
// Pushing the element : 5
// Pushing the element : 2
// Pushing the element : 11
// 1 5 2 11
// The front most value right now is : 1
// Popping 1
// Popping 5
// Pushing the element : 12
// Pushing the element : 8
// The front most value right now is : 2
// 2 11 12 8
