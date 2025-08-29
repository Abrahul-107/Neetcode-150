#include<iostream>
using namespace std;

vector<int>productOfArrayExceptItself(vector<int>&nums)
{
    int product = 1;
    int zeroCount = 0;
    int indexForZero = -1;

    for(int index=0;index<nums.size();++index)
    {
        if(nums[index]==0)
        {
            indexForZero = index;
            zeroCount++;
        }
        else
            product *= nums[index];
    }

    vector<int>ans(nums.size());
    
    if(zeroCount==0)
    {
        for(int index=0;index<nums.size();++index)
            ans[index] = product/nums[index];
    }
    if(zeroCount==1)
    {
       ans[indexForZero] = product;  
    }
    return ans;

}


int main()
{
    vector<int>nums = {1,2,3,4};
    vector<int>ans = productOfArrayExceptItself(nums);

    for(int element:ans)
        cout<<element<<" ";


    return 0;
}