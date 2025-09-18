# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int num[500010];
int dp[500010];
int mod_dp[500010];
int res;
int arr[500010];
int mx,mn=500001;
int seg[2000010];
void update(int v,int l,int r,int idx,int x)
{
    if(l>idx || r<idx) return;
    if(l==r)
    {
        seg[v]=x;
        return;
    }
    int mid=(l+r)/2;
    update(v*2,l,mid,idx,x);
    update(v*2+1,mid+1,r,idx,x);
    seg[v]=max(seg[v*2],seg[v*2+1]);
}
int query(int v,int l,int r,int st,int en)
{
    if(st>r || en<l)
        return 0;
    if(st<=l && en>=r)
        return seg[v];
    int mid=(l+r)/2;
    return max(query(v*2,l,mid,st,en),query(v*2+1,mid+1,r,st,en));
}
int main()
{
    fastio;
    int n,k,d;
    cin>>n>>k>>d;
    for(int i=1;i<=n;i++) 
    {
        cin>>arr[i];
        mx=max(mx,arr[i]);
        mn=min(mn,arr[i]);
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=max(mod_dp[arr[i]%k]+1,query(1,1,mx,max(mn,arr[i]-d),min(mx,arr[i]+d))+1);
        //cout<<mod_dp[arr[i]%k]<<" "<<dp[i]<<'\n';
        mod_dp[arr[i]%k]=dp[i];
        update(1,1,mx,arr[i],dp[i]);
        res=max(res,dp[i]);
    }
    cout<<res; 
}