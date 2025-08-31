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

void preOrderTraversal(TreeNode *root)
{
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode* currNode = q.front();
        q.pop();
        cout<<currNode->data<<" ";
        if(currNode->left) 
            q.push(currNode->left);
        if(currNode->right)
            q.push(currNode->right);
    }

}

int main()
{
    /*
        1
    2      3
   4 5    6  7
    */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    preOrderTraversal(root);


    return 0;
}