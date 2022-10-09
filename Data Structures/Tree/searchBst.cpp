#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *searchInBst(Node *root, int key)
{

    if (root == NULL)
        return NULL;

    if (root->data == key)
        return root;

    if (root->data > key)
    {
        return searchInBst(root->left, key);
    }
    else
    {
        return searchInBst(root->right, key);
    }
}

Node* inorderSucc(Node*root)
{
    Node* curr=root;
    while(curr && curr->left !=NULL){
        curr=curr->left;
    }
    return curr;
}

Node* deleteInBst(Node*root, int key)
{
    if(key< root->data){
        root->left=deleteInBst(root->left, key);
    }
    else if(key>root->data)
    {
        root->right=deleteInBst(root->right, key);
    }
    else{
        if(root->left==NULL)
        {
            Node* temp= root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            Node*temp=root->left;
            free(root);
            return temp;
        }
        //case 3
        Node* temp = inorderSucc(root->right);
        root->data=temp->data;
        root->right=deleteInBst(root->right,temp->data);

    }
    return root;

}

void inorder(Node*root)
{
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

 

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->right= new Node(3);
    root->left->left = new Node(1);
    root->right=new Node(5);
    root->right->right=new Node(6);
    
    if(searchInBst(root,5)==NULL)
    {
    cout<<"key don't exist"<<endl;
    }
    else
    {
    cout<<"key exist"<<endl;
    }

    inorder(root);
    root= deleteInBst(root,2);
    cout<<endl;
    inorder(root);


        return 0;
}