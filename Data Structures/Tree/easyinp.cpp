//Contributed By- Shashank Rai(shashank.rai00331@gmail.com)

#include <iostream>
#include <queue>
#include "treeNode.cpp"

using namespace std;

TreeNode<int> *easyinput()
{

    // this is the perfect usecase of queues , we will take help of queues to make this function take input in an easy way

    int rootData;
    cout << "Enter the root data" << endl;
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);

    // now we will make a queue to put elements of first node in it

    // datatype of queue is such because it will contain the first line of nodes which are treenode pointers
    queue<TreeNode<int> *> pendingnodes;

    pendingnodes.push(root); // pushed the first root node

    while (pendingnodes.size() != 0)
    {
        TreeNode<int> *front = pendingnodes.front();
        pendingnodes.pop();

        cout << "Enter the no of children of: " << front->data << endl;

        int numchild;
        cin >> numchild;

        for (int i = 0; i < numchild; i++)
        {
            int childData;
            cout << "Enter " << i << " child of :" << front->data << endl;

            cin >> childData;

            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingnodes.push(child);
        }
    }

    return root;
};

// finding number of nodes

int numNodes(TreeNode<int> *root)
{
    int ans = 1; // this is for the root node we are passing

    for (int i = 0; i < root->children.size(); i++)
    {

        ans += numNodes(root->children[i]);
    }

    return ans;
};

// height of the tree

void treeHeight()
{
}

// depth of the tree

void treeDepth(TreeNode<int> *root, int k)
{

    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        treeDepth(root->children[i], k - 1);
    }
}

// print function

void printTree(TreeNode<int> *root)
{

    if (root == NULL)
    { // if someone passes a null tree
      // edge case
        return;
    }

    cout << root->data << ":";
    // printing all other nodes

    for (int i = 0; i < root->children.size(); i++)
    {

        cout << root->children[i]->data << ",";
    }

    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {

        printTree(root->children[i]);
    }
};

void deleteTree(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }

    delete root;
}

// this function counts the leafnodes in the tree which do not have any children and prints them

int countLeafNode()
{
}

int main()
{

    // default tree;
    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

    TreeNode<int> *root = easyinput();
    cout << endl;

    printTree(root);

    // TODO ## DELETE THE TREE

    // if we delete the root node directly then what happens is the root node gets delete and we loose all other nodes we have created , they are dynamically allocated but not delete , we lost then , so we have to make a delete function to delete in postorder traversal

    // deleteTree is defined above

    deleteTree(root);

    // other way to delete is by calling the destructor and defining the destructor
    // check Treenode destructor

    // delete node;
    // this will call the destructor;
}