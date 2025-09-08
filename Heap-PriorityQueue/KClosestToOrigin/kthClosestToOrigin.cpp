#include<iostream>
using namespace std;


vector<vector<int>> kThClosest(vector<vector<int>>&points,int k)
{
    priority_queue<pair<int,vector<int>>>maxHeap;

    for(vector<int>point:points)
    {
        int x = point[0];
        int y = point[1];
        int distanceSquared = x*x+y*y;

        maxHeap.push({distanceSquared,point});
        
        if(maxHeap.size()>k)
           maxHeap.pop();
    }
    vector<vector<int>>ans;

    while(!maxHeap.empty())
    {
        vector<int>closest = maxHeap.top().second;
        ans.push_back(closest);
        maxHeap.pop();
    }
    
    return ans;
}




int main()
{
    // vector<vector<int>>points = {{1,3},{-2,2}};
    vector<vector<int>>points = {{3,3},{5,-1},{-2,4}};

    vector<vector<int>>ans = kThClosest(points,2);

    for (vector<int>& it : ans) 
    {
        for (int x : it) 
            cout << x << " ";
        
        cout << endl; 
    }
    
    return 0;

}