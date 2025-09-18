# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
#define inf 1e16
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,k;
ll arr[5010];
ll xr[5010][5010];
ll dp[5010][5010];
void dnc(int t,int s,int e,int l,int r)
{
    if(s>e) return;
    int mid=(s+e)/2;
    int idx=-1;
    for(int i=l;i<=min(r,mid);i++)
    {
        ll temp=dp[t-1][i-1]+xr[i][mid];
        if(temp>dp[t][mid])
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
        cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        ll temp=0;
        for(int j=i;j<=n;j++)
        {
            temp|=arr[j];
            xr[i][j]=temp;
        }
    }
    for(int i=1;i<=n;i++)
        dp[1][i]=xr[1][i];
    for(int i=2;i<=k;i++)
    {
        fill(dp[i],dp[i]+n+1,-1);
        dnc(i,i,n,i,n);
    }
    cout<<dp[k][n];
}