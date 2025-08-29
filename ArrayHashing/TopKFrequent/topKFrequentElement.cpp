#include<iostream>
using namespace std;

vector<int>topKfrequentElement(vector<int>&nums,int k)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int>ans;
    unordered_map<int,int>mp;
    
    for(auto num:nums)
        mp[num]++;
    
    for(auto it:mp)
    {
        pq.push({it.second,it.first});

        if(pq.size()>k)
            pq.pop();     
    }
    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}


int main()
{

    vector<int>arr = {1,1,1,2,2,3};
    int k = 2;
    vector<int>ans = topKfrequentElement(arr,k);

    for(auto ele:ans)
        cout<<ele<<" ";


    return 0;
}