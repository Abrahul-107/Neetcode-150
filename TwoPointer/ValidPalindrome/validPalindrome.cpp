#include<iostream>
using namespace std;

bool validPalindrome(string s)
{
    if(s.empty())
        return true;

    transform(s.begin(), s.end(), s.begin(), ::toupper);
    string check = "";

    for(char character : s)
        if(character <= 'Z' && character >= 'A')
            check += character;
    cout<<check<<endl;
    int start = 0;
    int end = check.size() -1;
    while (start<=end)
    {
        if(check[start]!=check[end])
            return false;
        start++;end--;
    }
    return true;
    
}


int main()
{
    string word = "A man, a plan, a canal: Panama";
    cout<<validPalindrome(word);

    return 0;
}