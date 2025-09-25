#include <iostream>
using namespace std;

int maxProductSubarray(vector<int>&nums)
{
    int currentMin = nums[0];
    int currentMax = nums[0];
    int maxProd = nums[0];
    for(int i=1;i<nums.size();++i)
    {
        if(nums[i]<0)
            swap(currentMax,currentMin);
        currentMax = max(nums[i],currentMax*nums[i]);
        currentMin = min(nums[i],currentMin*nums[i]);
        maxProd = max(maxProd,currentMax);

    }
    return maxProd;
}


int main()
{
    vector<int>arr = {2,3,-2,4};

    cout<<maxProductSubarray(arr);

    return 0;
}