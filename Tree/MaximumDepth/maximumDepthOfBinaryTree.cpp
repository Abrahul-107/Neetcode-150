#include<iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val):data(val),left(nullptr),right(nullptr){}
};

int maxDepth(TreeNode *root)
{
    if(root==nullptr)
        return 0;
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    return max(leftHeight,rightHeight)+1;
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout<<"Maximum Depth of tree: "<<maxDepth(root)<<endl;

    return 0;
}
