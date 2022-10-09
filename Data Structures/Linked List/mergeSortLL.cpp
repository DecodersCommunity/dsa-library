#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insertionAtEnd(node *&head, int data)
{
    node *n = new node(data);
    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// merge sort begins

node* midPoint(node*head)
{
    node*slow=head;
    node*fast=head->next;

    while(fast!=NULL and fast->next!=NULL) // as we cant find NULL->next
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
node *mergeLL(node *&a, node *&b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    node *result;

    if (a->data < b->data)
    {
        result = a;
        result->next = mergeLL(a->next, b);
    }
    else
    {
        result = b;
        result->next = mergeLL(a, b->next);
    }

    return result;
}

node *mergeSort(node *head)
{
    // base case
    if (head == NULL or head->next == NULL)
        return head;

    // rec case
    node *mid = midPoint(head);

    // break at the mid point
    node *a = head;
    node *b = mid->next;
    mid->next=NULL; // to break it into two different LL

    //recursive sort 
    a=mergeSort(a);
    b=mergeSort(b);

    //merge 
    return mergeLL(a,b);
}

int main()
{
    int a[] = {5, 2, 60, 45, 4};

    node *b = NULL;

    for (int i = 0; i < 5; i++)
    {
        insertionAtEnd(b, a[i]);
    }

    printLL(b);
    node*head=mergeSort(b);
    printLL(head);
}