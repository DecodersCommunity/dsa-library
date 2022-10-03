#include<iostream>
using namespace std;
class node{
public:
    int data;
    node * left;
    node * right;
};
node* createNode(int data){
    node * n = new node[sizeof(node)]; //* creating a node pointer
    (*n).data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void preOrder(node * root){
    if(root != NULL){
        cout<<root->data<<" ";

        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(node * root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);

        cout<<root->data<<" ";
    }
}
void inOrder(node * root){
    if(root != NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int isBST(node * root){
    static node * prev = NULL; //* it will be remebered
   if(root != NULL){         //* for all recursive calls
       if(!isBST(root->left)){
           return 0; //*false
       }
       if(prev != NULL && root->data <= prev->data){
           return 0;
       }
       prev = root;
       return isBST(root->right);
   }
   return 1;
}

int main(){
 /*   // * p for parent :)
    //* constructing the root node
     node * p = new node[sizeof(node)]; //* creating a node pointer
    (*p).data = 12;
    p->left = NULL;
    p->right = NULL;

    //* constucting the Second node
    node * p1 = new node[sizeof(node)];
    (*p1).data = 1;
    p1->left = NULL;
    p1->right = NULL;

    //* constructing the Third node
    node * p2 = new node[sizeof(node)];
    (*p2).data = 2;

    //* linking the root node with their children
    p->left = p1;
    p->right = p2; */

    node * p = createNode(5);
    node * p1 = createNode(3);
    node * p2 = createNode(6);
    node * p3 = createNode(1);
    node * p4 = createNode(4);
    //* the BST looks like this
    //*       5
    //*      / \
    //*     3   6
    //*    / \
    //*   1   4

    p->right = p2;
    p->left = p1;
    p1->left = p3;
    p1->right = p4;

    inOrder(p);
    cout<<endl;
    cout<<isBST(p)<<endl;
}
