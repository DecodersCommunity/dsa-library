// contributed by Yash Kumar <yashrathor5015@gmail.com>
// BST Iterator

#include <bits/stdc++.h>
using namespace std;

// Node of the binary tree
struct node
{
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Iterator for BST
class bstit
{
private:
    // Stack to store the nodes
    // of BST
    stack<node *> q;

public:
    // Constructor for the class
    bstit(node *root)
    {
        // Initializing stack
        node *curr = root;
        while (curr != NULL)
            q.push(curr), curr = curr->left;
    }

    // Function to return
    // current element iterator
    // is pointing to
    node *curr()
    {
        return q.top();
    }

    // Function to iterate to next
    // element of BST
    void next()
    {
        node *curr = q.top()->right;
        q.pop();
        while (curr != NULL)
            q.push(curr), curr = curr->left;
    }

    // Function to check if
    // stack is empty
    bool isEnd()
    {
        return !(q.size());
    }
};

// Function to iterator to every element
// using iterator
void iterate(bstit it)
{
    while (!it.isEnd())
        cout << it.curr()->data << " ", it.next();
}

// Driver code
int main()
{
    node *root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);

    // Iterator to BST
    bstit it(root);

    // Function to test iterator
    iterate(it);

    return 0;
}
