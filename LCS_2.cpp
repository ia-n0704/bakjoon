#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010];
string s,t;
void lcs(string s,string t)
{
    for(int i=1;i<=s.length();i++)
    {
        for(int j=1;j<=t.length();j++)
        {
            if(s[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    for(int i=1;i<=s.length();i++)
    {
        for(int j=1;j<=t.length();j++)
            cout<<dp[i][j]<<" ";
        cout<<'\n';
    }
    cout<<dp[s.length()][t.length()]<<'\n';
    int a=0,b=0;
    for(int i=1;i<=t.length();i++)
    {
        if(dp[s.length()][i]==dp[s.length()][t.length()])
        {
            a=i;
            break;
        }
    }
    for(int i=1;i<=s.length();i++)
    {
        if(dp[i][t.length()]==dp[s.length()][t.length()])
        {
            b=i;
            break;
        }
    }
    if(a<=b)
    {
        for(int i=1;i<=t.length();i++)
        {
            if(dp[s.length()][i]!=dp[s.length()][i-1])
                cout<<t[i-1];
        }        
    }
    else
    {
        for(int i=1;i<=s.length();i++)
        {
            if(dp[i][t.length()]!=dp[i-1][t.length()])
                cout<<s[i-1];
        }       
    }
}
int main()
{
    cin>>s>>t;
    lcs(s,t);
}