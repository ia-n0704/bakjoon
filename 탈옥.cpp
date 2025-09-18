#include <bits/stdc++.h>
using namespace std;
#define inf 1e16
typedef long long ll;
int n,m;
ll c[10010];
ll dp[1010][10010];
ll sum[10010];
ll f(int a,int b)
{
    return (sum[b]-sum[a-1])*(b-a+1);
}
void dnc(int t,int l,int r,int s,int e)
{
    int mid=(s+e)/2;
    if(s>e)
        return;
    int idx=-1;
    for(int i=l;i<=min(r,mid);i++)
    {
        ll temp=dp[t-1][i]+f(i+1,mid);
        if(temp<dp[t][mid])
        {
            dp[t][mid]=temp;
            idx=i;
        }
    }
    dnc(t,l,idx,s,mid-1);
    dnc(t,idx,r,mid+1,e);
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+c[i];
    for(int i=1;i<=n;i++)
        dp[1][i]=f(1,i);
    for(int i=2;i<=m;i++)
    {
        fill(dp[i],dp[i]+n+1,inf);
        dnc(i,1,n,1,n);
    }
    /*for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<'\n';
    }*/
    cout<<dp[m][n];
}