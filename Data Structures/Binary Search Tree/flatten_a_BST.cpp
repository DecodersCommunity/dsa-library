// contributed by- Yash Kumar <yashrathor5015@gmail.com>

// Flatten Binary Tree to Linked List

//  Time complexity- Time Complexity: O(N) Reason: The loop will execute for every node once.

// Space Complexity: O(N)

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

class Solution
{
    node *prev = NULL;

public:
    void flatten(node *root)
    {
        if (root == NULL)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int main()
{

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right = newNode(5);
    root->right->right = newNode(6);
    root->right->right->left = newNode(7);

    Solution obj;

    obj.flatten(root);
    while (root->right != NULL)
    {
        cout << root->data << "->";
        root = root->right;
    }
    cout << root->data;
    return 0;
}