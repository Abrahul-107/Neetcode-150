#include<iostream>
using namespace std;

vector<int> dailyTemperatures(vector<int>&temperatures)
{
    int size = temperatures.size();
    vector<int>ans(size,0);
    stack<int>st;

    for(int index=0;index<size;++index)
    {
        while(!st.empty() && temperatures[st.top()]<temperatures[index])
        {
            ans[st.top()] = index - st.top();
            st.pop();
        }
        st.push(index);
    }
    return ans;
}




int main()
{
    vector<int>temperatures = {73,74,75,71,69,72,76,73};
    vector<int>ans = dailyTemperatures(temperatures);
    for(auto element:ans)
        cout<<element<<" ";
    return 0;

}