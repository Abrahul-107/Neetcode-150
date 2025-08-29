#include<iostream>
using namespace std;


vector<vector<string>> groupAnagram(vector<string>&strings)
{
    vector<vector<string>>ans;
    unordered_map<string,vector<string>>mp;
    for(string word : strings)
    {
        string sortedWord = word;
        sort(sortedWord.begin(),sortedWord.end());
        mp[sortedWord].push_back(word);
    }
    for(auto anagramList:mp)
        ans.push_back(anagramList.second);
    return ans;
}

int main()
{
    vector<string>strings = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagram(strings);
    for(auto list:ans)
    {
        for(auto stringList:list)
            cout<<stringList<<" ";
        cout<<endl;
    }



    return 0;
}