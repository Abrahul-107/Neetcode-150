#include<iostream>
using namespace std;

int kthLargestElement(vector<int>&arr,int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;  
    for(auto num:arr)
    {
        minHeap.push(num);
        if(minHeap.size()>k)
            minHeap.pop();
    }
    return minHeap.top();
    
}


int main()
{
    vector<int>arr = {5,6,1,2,8,90,23};
    int k = 2;
    cout<<kthLargestElement(arr,k);


    return 0;
}