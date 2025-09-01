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

int maxDepthBalanced(TreeNode *root)
{
    if(!root)   
        return 0;

    int leftHeight = maxDepthBalanced(root->left);
    if(leftHeight==-1)
        return -1;

    int rightHeight = maxDepthBalanced(root->right);
    if(rightHeight==-1)
        return -1;
    if(abs(leftHeight-rightHeight)>1)
        return -1;
    return max(leftHeight,rightHeight)+1;


}
bool isBalanced(TreeNode *root)
{
    if(maxDepthBalanced(root)==-1)
        return false;
    return true;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);

    cout<<"Is the tree balanced? ";
    if(isBalanced(root))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
