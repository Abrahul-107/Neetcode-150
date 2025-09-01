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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if(!p && !q) return true;
    if(!p || !q) return false;
    if(p->data != q->data) return false;
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}

int main()
{
    // First tree
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    // Second tree
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    cout<<"Are the two trees same? ";
    if(isSameTree(root1, root2))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
