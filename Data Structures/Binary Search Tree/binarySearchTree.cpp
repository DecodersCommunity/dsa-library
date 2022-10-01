// Contributed by - Akhil Kumar Sharma <sharma.akhil484@gmail.com>

#include<iostream>

using namespace std;

struct bnode
{
	int data;
	bnode *left;
	bnode *right;
};

bnode* createnewnode(int data)
{
	bnode *node=new bnode();
	node->data=data;
	node->left=node->right=NULL;
	return node;
}

bnode* insert(bnode *root,int data)
{
	if(root==NULL)
	{
		root=createnewnode(data);
	}
	else if(data<=root->data)
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
	return root;
}

bool search(bnode *root,int data)
{
	if(root==NULL)
	{
		return false;
	}
	else if(root->data==data)
	{
		return true;
	}
	else if(data<=root->data)
	{
		return search(root->left,data);
	}
	else
	{
		return search(root->right,data);
	}
	return false;
}

bnode* mini(bnode *root)
{
	if(root==NULL)
	{
		cout<<"empty";
		return NULL;
		
	}
	else if(root->left==NULL && root->right==NULL)
	{
		return root;
	}
	else
	{
		while(root->left!=NULL)
		{
			root = (root->left);
		}
		return root;
	}
}

bnode *del(bnode *root,int value)
{
	if(root==NULL)
	{
		cout<<"Not Found"<<endl;
		return root;
	}
	if(root->data>value)
	{
		root->left=del(root->left,value);
	}
	else if(root->data<value)
	{
		root->right=del(root->right,value);
	}
	else
	{
		if(root->right==NULL && root->left==NULL)
		{
			delete root;
			root=NULL;			//that address is empty but root is a pointer to node so it is not empty.
			return root;
		}
		else if(root->right==NULL)
		{
			bnode *temp=root;
			root=root->left;
			delete temp;
			return root;
		}
		else if(root->left==NULL)
		{
			bnode *temp=root;
			root=root->right;
			delete temp;
			return root;
		}
		else
		{
			bnode *temp=mini(root->right);        //find node with minimum value in right subtree
			root->data=temp->data;
			root->right=del(root->right,temp->data);
		}

	}
	return root;
}

void Inorder(bnode *root)
{
	if(root==NULL)
		return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
	
}

int main()
{
	int item,n,num;
	bnode *root=NULL;
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,12);
	root=insert(root,17);
	root=insert(root,25);
	root=insert(root,6);
	root=insert(root,11);
	root=insert(root,16);
	root=insert(root,27);
	Inorder(root);
	cout<<"\n";
	root=del(root,25);
	Inorder(root);
	cout<<"\n";

	if(search(root,16)==true)
		cout<<"Found"<<"\n";
	else
		cout<<"Not found"<<"\n";
	return 0;


}