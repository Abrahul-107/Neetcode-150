#include<iostream>
using namespace std;

int robMax(vector<int>&nums,int left,int right)
{
    if(left==right) return nums[left];
    if(left+1==right) return max(nums[left],nums[right]);

    int prev2 = nums[left];
    int prev = max(nums[left],nums[left+1]);
    int maxRob = 0;


    for(int i=left+2;i<=right;++i)
    {
        maxRob = max(prev,prev2+nums[i]);
        prev2 = prev;
        prev = maxRob;
    }
    return prev;

}
int rob(vector<int>&nums)
{
    int n = nums.size();
    if(n<2)
        return nums[0];
    return max(robMax(nums,0,n-2),robMax(nums,1,n-1));

}


int main()
{
    vector<int>nums = {2,3,2};
    cout<<rob(nums);

    return 0;

}