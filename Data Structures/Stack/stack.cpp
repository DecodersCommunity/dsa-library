/*
**  File Contributed by - Harshit Sharma <harshits908@gmail.com>
*/

#include <iostream>
using namespace std;

#define SIZE 10

class STACK
{
    private:
        int num[SIZE];
        int top;
    public:
        STACK();                // default constructor
        int push(int);          // push operation
        int pop();              // pop operation
        int isEmpty();
        int isFull();
        void displayItems();
};


int main()
{
    STACK stk;
    int choice, n,temp;
    do
    {
        cout << endl;
        cout << "0 - Exit." << endl;
        cout << "1 - Push Item." << endl;
        cout << "2 - Pop Item." << endl;
        cout << "3 - Display Items (Print STACK)." << endl;
        
        cout<<"Enter your choice: ";
        cin >> choice;
         
        switch(choice)
        {
            case 0: break;
             
            case 1:
                cout << "Enter item to insert: ";
                cin >> n;
                temp = stk.push(n);
                if(temp==0)
                    cout << "STACK is FULL." << endl;
                else
                    cout << temp<< " inserted." << endl;
            break;
                 
            case 2:
                temp = stk.pop();
                if (temp==0)
                    cout << "STACK IS EMPTY." << endl;
                else
                    cout << temp << " is removed (popped)." << endl;
            break;
             
            case 3:
                stk.displayItems();
                break;
             
            default:
                cout << "An Invalid choice." << endl;
        }   
    } while (choice!=0);
 
    return 0;
}


STACK::STACK()
{
    top = -1;
}

int
STACK::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;   
}
 
int
STACK::isFull()
{
    if (top == (SIZE-1))
        return 1;
    else
        return 0;
}
 
int
STACK::push(int n)
{
    if (isFull())
    {
        return 0;
    }
    ++top;
    num[top] = n;
    return n;
}
 
int
STACK::pop()
{
    int temp;
    if(isEmpty())
        return 0;
    temp=num[top];
    --top;
    return temp;
     
}
 
void
STACK::displayItems()
{
    cout << "STACK is: " ;
    for(int i=top ; i>=0 ; i--)
        cout << num[i] << " ";

    cout << endl;
}
