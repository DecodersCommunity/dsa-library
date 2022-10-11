#include <bits/stdc++.h>
using namespace std;

void insert_at_bottom(int x, stack<int> &st)
{
    // base case
    if (st.empty())
    {
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();
    insert_at_bottom(x, st);
    st.push(temp);
}

void reverse(stack<int> &st)
{
    // base case
    if (st.empty())
    {
        return;
    }

    int x = st.top();
    st.pop();
    reverse(st);
    insert_at_bottom(x, st);
}

// display the stack
void display(stack<int> st)
{
    if (st.empty())
    {
        return;
    }

    int x = st.top();
    st.pop();
    cout << endl;
    cout << x << endl;
    ;
    display(st);
    st.push(x);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << "Original stack: ";
    display(st);
    reverse(st);
    cout << "Reversed stack: ";
    display(st);
    return 0;
}