#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a,b,c,d;
ll dp[2020][2020];
ll arr[2020],brr[2020];
ll res=2e9;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin>>n;
    string s,t;
    cin>>s>>t;
    cin>>a>>b>>c>>d;
    for(ll i=0;i<s.length();i++)
        if(s[i]=='1') arr[i+1]=1;
    for(ll i=0;i<t.length();i++)
        if(t[i]=='1') brr[i+1]=1;
    for(ll i=0;i<=n+15;i++)
    {
        for(ll j=0;j<=n+15;j++)
            dp[i][j]=2e9;
    }
    dp[0][0]=0;
    for(ll i=0;i<=n+8;i++)
    {
        for(ll j=0;j<=n+8;j++)
        {
            if(arr[i+1]==0) dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            if(brr[j+1]==0) dp[i][j+1]=min(dp[i][j+1],dp[i][j]);

            dp[i][j+1]=min(dp[i][j+1],dp[i][j]+a);
            dp[i][j+3]=min(dp[i][j+3],dp[i][j]+b);
            dp[i][j+5]=min(dp[i][j+5],dp[i][j]+c);

            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a);
            dp[i+3][j]=min(dp[i+3][j],dp[i][j]+b);
            dp[i+5][j]=min(dp[i+5][j],dp[i][j]+c);

            if(i==j) dp[i+4][j+4]=min(dp[i+4][j+4],dp[i][j]+d);
            //cout<<dp[i][j]<<" ";
        }
        //cout<<'\n';
    }
    for(ll i=n;i<=n+8;i++)
    {
        for(ll j=n;j<=n+8;j++)
            res=min(res,dp[i][j]);
    }
    cout<<res;
}