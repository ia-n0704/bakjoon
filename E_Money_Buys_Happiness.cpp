# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mx 1e18
ll c[100],h[100];
ll dp[55][50010];
void sol()
{
    ll m,x;
    ll sum=0;
    cin>>m>>x;
    for(int i=1;i<=m;i++) cin>>c[i]>>h[i];
    for(int i=1;i<=m;i++) sum+=h[i];
    for(int i=0;i<=m;i++)
        fill(dp[i],dp[i]+sum+1,mx);
    dp[0][0]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j-h[i]>=0)
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j-h[i]]+c[i]);
            }
            if((i-1)*x<dp[i][j])
                dp[i][j]=mx;
        }
    }
    ll res=0;
    for(int i=0;i<=sum;i++)
    {
        if(dp[m][i]!=mx) res=i;
    }
    cout<<res<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}