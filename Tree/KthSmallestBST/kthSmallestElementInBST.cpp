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

void kthSmallestDFS(TreeNode *root,int &count,int k,int &ans)
{
    if(root==nullptr)
        return;
    kthSmallestDFS(root->left,count,k,ans);
    count++;
    if(count==k)
    {
        ans = root->data;
        return;
    }
    kthSmallestDFS(root->right,count,k,ans);

}
int kthSmallest(TreeNode *root,int k)
{
    int count =0;
    int ans;
    kthSmallestDFS(root,count,k,ans);
    return ans;

}

int main()
{

   TreeNode *root = new TreeNode(5);
   root->left = new TreeNode(3);
   root->right = new TreeNode(7);
   root->left->left = new TreeNode(2);
   root->left->right = new TreeNode(4);
   root->right->left = new TreeNode(6);
   root->right->right = new TreeNode(8);

    cout<<kthSmallest(root,4);


    return 0;
}