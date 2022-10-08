// Contributed by - Abhishek Swaroop Shrivastava <gh4abhi@gmail.com>
// Problem Link - https://www.codingninjas.com/codestudio/problems/inorder-traversal_3839605?topList=striver-sde-sheet-problems

#define ll int
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void inorder(TreeNode* root, vector<ll>& ans)
{
    if(root==nullptr)
        return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<ll> ans;
    inorder(root,ans);
    return ans;
}