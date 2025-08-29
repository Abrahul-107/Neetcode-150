#include<iostream>
using namespace std;

bool anagramCheck(string firstString, string secondString)
{
    if(firstString.length() != secondString.length())
        return false;

    vector<int>charMap(firstString.length(),0);
    for(int index=0;index<firstString.length();++index)
    {
        charMap[firstString[index]-'a']++;
        charMap[secondString[index]-'a']--;
    }
    for(int count:charMap)
        if(count!=0)
            return false;
    return true;

}


int main()
{
    string firstString = "anagram";
    string secondString = "nagaram";

    cout<<anagramCheck(firstString,secondString);
    return 0;


}

