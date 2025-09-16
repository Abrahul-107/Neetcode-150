#include<iostream>
using namespace std;


int getIndexOfTarget(vector<int>rotatedArray,int target)
{
    int left = 0;
    int right = rotatedArray.size()-1;

    while (left<=right) 
    {
        int mid = left + (right-left) /2;
        if(rotatedArray[mid]==target)
        return mid;
     
        if(rotatedArray[left]<=rotatedArray[mid])
        {
            if(rotatedArray[left]<=target && rotatedArray[mid]>target)
                right = mid-1;
            else
                left = mid+1;
        }
        else
        {
            if(rotatedArray[mid]<target && rotatedArray[right]>=target)
                left = mid +1;
            else
                right = mid-1;
        }
    }
    return -1;
    
}


int main()
{
    vector<int>rotatedArray = {4,5,6,7,0,1,2};
    int target = 0;
    cout<<getIndexOfTarget(rotatedArray,target);

    return 0;

}