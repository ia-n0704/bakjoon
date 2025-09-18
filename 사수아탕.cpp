# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define inf 1e16
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
ll m;
ll arr[310];
ll dp[5][310][310];
ll ans;
ll sasu(int num,int l,int r,int cnt)
{
    if(cnt==0) return 0;
    if(dp[num][l][r]!=-1)
        return dp[num][l][r];
    ll temp=inf;
    ll next;
    if(num) next=arr[r];
    else next=arr[l];
    if(l)
    {
        //cout<<next<<" "<<arr[l-1]<<" "<<cnt*(next-arr[l-1])<<" ";
        temp=cnt*(next-arr[l-1])+sasu(0,l-1,r,cnt-1);
        dp[num][l][r]=temp;
        //cout<<temp<<'\n';
    }
    if(r<n-1)
    {
        temp=min(temp,cnt*(arr[r+1]-next)+sasu(1,l,r+1,cnt-1));
        dp[num][l][r]=temp;
    }
    return temp;
}
int main()
{
    fastio;
    cin>>n>>m;
    int flag=0;
    for(int i=0;i<n;i++) 
    {
        cin>>arr[i];
        if(arr[i]==0) flag=1;
    }
    if(!flag)
        arr[n++]=0;
    sort(arr,arr+n);
    int st=lower_bound(arr,arr+n,0)-arr;
    for(int i=0;i<n;i++)
    {
        /*for(int j=0;j<n;j++)
        {
            for(int r=0;r<n;r++)
                dp[0][j][r]=dp[1][j][r]=-inf;
        }*/memset(dp,-1,sizeof dp);
        ans=max(ans,m*i-sasu(0,st,st,i));
        //cout<<ans<<'\n';
    }
    cout<<ans+m*flag;
}