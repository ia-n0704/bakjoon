#include <bits/stdc++.h>
using namespace std;
long long dp[10010];
int main()
{
    int n,m;
    cin>>n>>m;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            dp[i]+=dp[j];
            dp[i]%=1999;
        }
    }
    dp[n]*=2;
    dp[n]--;
    dp[n]%=1999;
    int temp=dp[n-1]*2;
    for(int i=n+1;i<=m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i]+=dp[i-j];
            dp[i]%=1999;
        }
        dp[i]+=temp*dp[i-n];
        dp[i]%=1999;
    }
    cout<<dp[m];
}