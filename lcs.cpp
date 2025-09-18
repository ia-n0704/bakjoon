# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
string s,t,res;
int dp[4010][4010];
int main()
{
    fastio;
    cin>>s>>t;
    for(int i=0;i<s.length();i++)
    {
        for(int j=0;j<t.length();j++)
        {
            if(s[i]==t[j]) dp[i+1][j+1]=dp[i][j]+1;
            else
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
        }
    }
    int x=s.length(),y=t.length();
    while(1)
    {
        if(dp[x][y]==0) break;
        if(s[x-1]==t[y-1])
        {
            res+=s[x-1];
            x--,y--;
        }
        else
        {
            if(dp[x-1][y]>dp[x][y-1])
                x--;
            else y--;
        }
    }
    reverse(res.begin(),res.end());
    cout<<dp[s.length()][t.length()]<<'\n'<<res;
}