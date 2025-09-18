# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll arr[200010],dp[200010];
void sol()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    ll mx=0;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=arr[i];
        if(sum<0) sum+=mod;
        else sum%=mod;
        dp[i]=max(dp[i-1]+arr[i],arr[i]);
        mx=max(mx,dp[i]);
    }
    //cout<<mx<<'\n';
    for(int i=1;i<=m;i++)
    {
        sum+=mx;
        mx*=2;
        if(sum<0) sum+=mod;
        else sum%=mod;
        if(mx<0) mx+=mod;
        else mx%=mod;
    }
    cout<<sum<<'\n';
    fill(arr,arr+n+1,0);
    fill(dp,dp+n+1,0);
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