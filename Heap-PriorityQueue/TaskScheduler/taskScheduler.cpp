#include<iostream>
using namespace std;

int leastInterval(vector<char>&tasks,int gap)
{
    unordered_map<char,int>freq;

    for(char &it:tasks)
        freq[it]++;

    priority_queue<int>maxHeap;
    for(auto &it:freq)
        maxHeap.push(it.second);
    
    int time = 0;

    while (!maxHeap.empty())
    {
        vector<int>temp;
        for(int i=0;i<=gap;++i)
        {
            temp.push_back(maxHeap.top()-1);
            maxHeap.pop();
        }

        for(auto &it:temp)
        {
            if(it>0)
                maxHeap.push(it);
        }

        if(maxHeap.empty())
            time += temp.size();
        else
            time += (gap+1);

    }

    return time;

}


int main()
{
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int gap = 2;
    cout<<leastInterval(tasks,gap);

    return 0;

}