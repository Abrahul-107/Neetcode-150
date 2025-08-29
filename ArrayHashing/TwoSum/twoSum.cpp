#include<iostream>
using namespace std;


//Using hashmap tc: O(N) sc: O(N)
vector<int> twoSumUsingMap(vector<int>&nums,int target)
{
    unordered_map<int,int>mp;
    for(int index=0;index<nums.size();++index)
    {
        int rest = target - nums[index];
        if(mp.find(rest) != mp.end())
            return {rest,nums[index]};
        mp[nums[index]] = index;
    }
    return {-1,-1};

}

//Using sorting
vector<int> twoSumUsingSorting(vector<int>&nums,int target)
{
    sort(nums.begin(),nums.end());
    int firstIndex = 0;
    int LastIndex = nums.size() -1;
    while (firstIndex<LastIndex)
    {
        int sum = nums[firstIndex] + nums[LastIndex];
        if(sum>target)
            LastIndex--;
        else if(sum==target)
            return{nums[firstIndex],nums[LastIndex]};
        else
            firstIndex++;
    }
    return {-1,-1};
}

int main()
{
    vector<int>nums = {2,7,11,15};
    int target = 9;
    vector<int>ans = twoSumUsingSorting(nums,target);
    for(auto num:ans)
        cout<<num<<" ";

    return 0;
}