#include<iostream>
using namespace std;

int lengthOfSubstringWithoutRepeatingCharacter(string s)
{
    vector<int>hash(256,-1);
    int leftPointer = 0, rightPointer = 0;
    int size = s.size();
    int maxLen = INT_MIN;

    while(rightPointer<size)
    {
        if(hash[s[rightPointer]] != -1)
            leftPointer = max(leftPointer,hash[s[rightPointer]]+1);

        hash[s[rightPointer]] = rightPointer;
        maxLen = max(maxLen,rightPointer-leftPointer+1);
        rightPointer++;
    }
    return maxLen;
}




int main()
{
    string s = "abcabcbb";


    return 0;

}