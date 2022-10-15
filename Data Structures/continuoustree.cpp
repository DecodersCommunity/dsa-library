// Ameyanshu mishra <ameyanshumishra@gmail.com>
#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node
{
	int data;
	struct Node* left, * right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return(node);
}

// Function to check tree is continuous or not
bool treeContinuous(struct Node *ptr)
{
	// if next node is empty then return true
	if (ptr == NULL)
		return true;

	// if current node is leaf node then return true
	// because it is end of root to leaf path
	if (ptr->left == NULL && ptr->right == NULL)
		return true;

	// If left subtree is empty, then only check right
	if (ptr->left == NULL)
	return (abs(ptr->data - ptr->right->data) == 1) &&
			treeContinuous(ptr->right);

	// If right subtree is empty, then only check left
	if (ptr->right == NULL)
	return (abs(ptr->data - ptr->left->data) == 1) &&
			treeContinuous(ptr->left);

	// If both left and right subtrees are not empty, check
	// everything
	return abs(ptr->data - ptr->left->data)==1 &&
			abs(ptr->data - ptr->right->data)==1 &&
			treeContinuous(ptr->left) &&
			treeContinuous(ptr->right);
}

/* Driver program to test mirror() */
int main()
{
	struct Node *root = newNode(3);
	root->left	 = newNode(2);
	root->right	 = newNode(4);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->right = newNode(5);
	treeContinuous(root)? cout << "Yes" : cout << "No";
	return 0;
}
