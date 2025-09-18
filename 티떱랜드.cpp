# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define inf 1e16
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll u[4010][4010];
ll sum[4010][4010];
ll c[4010][4010];
ll dp[810][4010];
ll n,k;
void dnc(int t,int s,int e,int l,int r)
{
    if(s>e) return;
    int mid=(s+e)/2;
    int idx=-1;
    for(int i=l;i<=min(r,mid-1);i++)
    {
        ll temp=dp[t-1][i]+c[i+1][mid];
        if(temp<dp[t][mid])
        {
            dp[t][mid]=temp;
            idx=i;
        }
    }
    dnc(t,s,mid-1,l,idx);
    dnc(t,mid+1,e,idx,r);
}
int main()
{
    fastio;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>u[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sum[i][j]=sum[i][j-1]+u[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            c[i][j]=c[i][j-1]+sum[j][j]-sum[j][i-1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        dp[1][i]=c[1][i];
        //cout<<dp[1][i]<<" ";
    }
    for(int i=2;i<=k;i++)
    {
        fill(dp[i],dp[i]+n+1,inf);
        dnc(i,i,n,i-1,n-1);
    }
    cout<<dp[k][n];
}