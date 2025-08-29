#include<iostream>
using namespace std;

int maxArea(vector<int>&heights)
{
    int maxArea = INT_MIN;
    int startPointer = 0;
    int endPointer = heights.size() - 1;

    while (startPointer<endPointer)
    {
        int breadth = endPointer - startPointer;
        int length = min(heights[startPointer],heights[endPointer]);
        int currentArea = breadth * length;
        maxArea = max(currentArea,maxArea);

        if(heights[startPointer]<heights[endPointer])
            startPointer++;
        else
            endPointer--;
    }
    return maxArea;
    
}

int main()
{
    vector<int>height = {1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height);

    return 0;

}