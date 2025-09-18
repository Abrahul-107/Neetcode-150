#include<iostream>
using namespace std;

int minInRotatedSorted(vector<int>rotatedArray)
{
    int left = 0;
    int right = rotatedArray.size()-1;

    while (left<right)
    {
        int mid = left + (right-left) / 2; 
        
        // If mid element < high element, min is in left half
        if(rotatedArray[mid]<rotatedArray[right])
            right = mid;
        else
            left = mid + 1;
    }
    return rotatedArray[left];
    
}

int main()
{
    vector<int>rotatedSorted = {3,4,5,1,2};
    cout<<minInRotatedSorted(rotatedSorted);
    return 0;

}