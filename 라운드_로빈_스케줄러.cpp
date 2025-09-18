# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
ll arr[100010];
pll brr[100010];
int seg[400010];
ll ans[100010];
void update(int v,int l,int r,int idx)
{
    if(l==r && l==idx)
    {
        seg[v]=1;
        return;
    }
    if(l>idx || r<idx) return;
    int mid=(l+r)/2;
    update(v*2,l,mid,idx);
    update(v*2+1,mid+1,r,idx);
    seg[v]=seg[v*2]+seg[v*2+1];
}
ll query(int v,int l,int r,int st,int en)
{
    //cout<<v<<" "<<l<<" "<<r<<" "<<st<<" "<<en<<'\n';
    if(st>r || en<l) return 0;
    if(st<=l && en>=r) return seg[v];
    int mid=(l+r)/2;
    return query(v*2,l,mid,st,en)+query(v*2+1,mid+1,r,st,en);
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++)
        brr[i]={arr[i],i};
    sort(brr+1,brr+n+1);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        int a=query(1,1,n,brr[i].second,n);
        //cout<<a<<" ";
        ll res=(n-i+1)*brr[i].first+sum-(n-brr[i].second-a);
        //cout<<res<<'\n';
        ans[brr[i].second]=res;
        sum+=brr[i].first;
        update(1,1,n,brr[i].second);
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<'\n';
}