#include<iostream>
using namespace std;

int rainTrappingWater(vector<int>&height)
{
    int size = height.size();
    int leftPointer = 0;
    int rightPointer = size-1;
    int leftMax = height[leftPointer], rightMax = height[rightPointer];
    int maxTrap = 0;

    while (leftPointer<rightPointer)
    {
        if(leftMax<rightMax)
        {
            leftPointer++;
            leftMax = max(leftMax,height[leftPointer]);
            maxTrap += leftMax - height[leftPointer];
        }
        else
        {
            rightPointer--;
            rightMax = max(rightMax,height[rightPointer]);
            maxTrap += rightMax - height[rightPointer];

        }
    }
    return maxTrap;
    
}

int main()
{
    vector<int>arr = {4,2,0,3,2,5};
    cout<<rainTrappingWater(arr);

    return 0;
}