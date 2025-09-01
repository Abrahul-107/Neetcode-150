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

void invertTree(TreeNode *root)
{
    if(root==nullptr)
        return ;

    swap(root->left,root->right);
    invertTree(root->left);
    invertTree(root->right);
}

void printInorder(TreeNode *root)
{
    if(root==nullptr)
        return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
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

    cout<<"Original tree (Inorder): ";
    printInorder(root);
    cout<<endl;

    invertTree(root);

    cout<<"Inverted tree (Inorder): ";
    printInorder(root);
    cout<<endl;

    return 0;
}
