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

int maxDepthOfBT(TreeNode *root,int &diameter)
{
    if(!root)
        return 0;
    int leftHeight = maxDepthOfBT(root->left,diameter);
    int rightHeight = maxDepthOfBT(root->right,diameter);
    diameter = max(diameter, leftHeight+rightHeight);
    return max(leftHeight,rightHeight)+1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;
    maxDepthOfBT(root,diameter);
    return diameter;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout<<"Diameter of tree: "<<diameterOfBinaryTree(root)<<endl;

    return 0;
}
