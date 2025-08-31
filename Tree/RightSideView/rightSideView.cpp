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

void rightSideViewDFS(TreeNode *root,vector<int>&ans,int level)
{
    if(root==nullptr)
        return;
    if(level==ans.size())
        ans.push_back(root->data);
    rightSideViewDFS(root->right,ans,level+1);
    rightSideViewDFS(root->left,ans,level+1);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int>ans;
    int level = 0;
    rightSideViewDFS(root,ans,level);
    return ans;

}

int main()
{
    /*
        1
    2      3
   4 5    6  7
      13
    */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(13);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);


    vector<int>ans = rightSideView(root);
    for(auto it:ans)
        cout<<it<<" ";


    return 0;
}