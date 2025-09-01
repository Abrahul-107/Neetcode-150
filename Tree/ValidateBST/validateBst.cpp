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

bool validBst(TreeNode *root,int &previousValue)
{
    if(root==nullptr)
        return true;
    if(!validBst(root->left,previousValue))
        return false;
    if(root->data < previousValue)
        return false;
    previousValue = root->data;
    return validBst(root->right,previousValue);

    
}

int main()
{
    /*
    
            4

        2       6
    1      3  5     7

    */
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    int previousValue = INT_MIN;
    cout<<validBst(root,previousValue);

    return 0;


}