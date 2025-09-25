#include<iostream>
using namespace std;

int memo[100];

int decodeWays(string &s)
{
    int n = s.length();
    if( s == "0" || n==0 )
        return 0;
    vector<int>dp(n+1,0);
    dp[0] = 1;
    dp[1] = s[0]!='0' ? 1:0;

    for(int i=2;i<=n;i++)
    {
        if(s[i-1] != '0')
            dp[i] += dp[i-1];
        if(s[i-2]== '1' || (s[i-2]=='2' && s[i-1]<='6'))
            dp[i] += dp[i-2];
    }
    return dp[n];

}

int solveRecursion(int index,string &s,int n)
{
    if(memo[index] != -1)
        return memo[index];

    if(index==n)
        return memo[index] =  1;
    if(s[index]=='0')
        return memo[index] =  0;

    int ways = solveRecursion(index+1,s,n);
    if(index+1<n)
    {
        if(s[index]=='1' || (s[index]=='2' && s[index+1]<='6'))
            ways += solveRecursion(index+2,s,n);
    }
    return memo[index] = ways;
   
}

int decodeWaysRecusrionCall(string &s)
{
    int n = s.length();

    // Initialize memo with -1 before every call
    for(int i = 0; i <= n; i++)
        memo[i] = -1;
        
    return solveRecursion(0,s,n);



}

int main()
{
    string s = "12";
    cout<<decodeWays(s);

    return 0;


}