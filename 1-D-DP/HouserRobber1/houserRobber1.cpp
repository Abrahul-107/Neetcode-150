#include<iostream>
using namespace std;

int robDpWithoutSpaceOptimization(vector<int>&nums)
{
    int size = nums.size();
    if(size==1)
        return nums[0];
    vector<int>dp(size+1,0);
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);

    for(int index=2;index<size;++index)
        dp[index] = max(dp[index-1],nums[index]+dp[index-2]);
    return dp[size-1];
}

int rob(vector<int>&nums)
{
    if(nums.size()<2)
        return nums[0];

    int prev2 = nums[0];
    int prev = max(nums[0],nums[1]);
    int maxRob = 0;

    for(int i=2;i<nums.size();++i)
    {
        maxRob = max(prev,nums[i]+prev2);
        prev2 = prev;
        prev = maxRob;
    }
    return prev;

}

int main()
{
    vector<int>nums = {1,2,3,1};
    cout<<robDpWithoutSpaceOptimization(nums)<<endl;
    cout<<rob(nums);

    return 0;


}