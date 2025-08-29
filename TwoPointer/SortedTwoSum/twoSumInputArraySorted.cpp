#include<iostream>
using namespace std;

vector<int> twoSumInputArraySorted(vector<int>&nums,int target)
{
    int startIndex = 0;
    int endIndex = nums.size()-1;
    while (startIndex<endIndex)
    {
        int twoSum = nums[startIndex] + nums[endIndex];
        if(twoSum<target)
            startIndex++;
        else if (twoSum==target)
            return {startIndex,endIndex};
        else
            endIndex--;
        
    }
    return {-1,-1};
    
}   


int main()
{
    vector<int>arr = {2,3,4};
    int target = 6;

    vector<int>ans = twoSumInputArraySorted(arr,target);


}