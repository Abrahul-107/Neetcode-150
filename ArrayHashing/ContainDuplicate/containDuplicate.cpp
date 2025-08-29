#include<iostream>
using namespace std;

//Optimized
bool containDuplicateOptimized(vector<int>&nums)
{
    unordered_map<int,int>mp;
    for(auto num:nums)
    {
        mp[num]++;
        if(mp[num]>1)
            return true;
    }
    return false;
}

//Bruteforce
bool containDuplicate(vector<int>&nums)
{
    sort(nums.begin(),nums.end());
    int size = nums.size();

    for(int index=1;index<size;++index)
    {
        if(nums[index]==nums[index-1])  
            return true;
    }
    return false;

}

int main()
{
    vector<int>nums = {1,2,3,1};
    cout<<containDuplicate(nums)<<endl;
    cout<<containDuplicateOptimized(nums);

    return 0;

}