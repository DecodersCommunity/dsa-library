//Contributed By- Shashank Rai(shashank.rai00331@gmail.com)


#include <vector>
using namespace std;

template <typename T>

// we are defining a Tree node using vector here just as we defined the linkedlist nodes .

class TreeNode
{
public:
    T data;
    vector<TreeNode *> children;

    //          OR

    //    vector<TreeNode<T>*> children

    // we can also define the type of TreeNode datatype or the system will assume by itself as defined above .

    // If the parent has T type data then the children will automatically have T type data .

    // TreeNode*  ==> these are treenode pointers defined
    // children is a vector of datatype treenode* pointer

    TreeNode(T data)
    { // constructor called

        this->data = data;
    }
    ~TreeNode()
    {
        // when we call a destructor for anything then the destructor function is first executed and then the passed parameter is deleted .

        // Basically this inner part is executed first so here we can define a loop for deleting the children of the Treenode;

        // here children.size() means the children of the parameter on which the destructor is called

        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];

            // delete keyword calls the destructor everytime;
        }
    }
};

// type of traversals

// PREORDER  ==> parent says first print me and then my children

void preorder(TreeNode<int> *root)
{
    cout << root->data << " ";

    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}

// POSTORDER ==>  root says first print my children and then print me

// check and write code for post order traversal;

void postorder(TreeNode<int> *root)
{

    // if(root == NULL){
    //     return;
    // }

    // for(int i =0; i<root->children.size(); i++){
    //      preorder(root->children[i]);
    //  }
    //  cout<<root ->data << " ";
}