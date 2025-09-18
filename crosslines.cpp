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
ll arr[500010];
ll seg[2000010];
void update(int v,int l,int r,int x)
{
    if(r<x || l>x) return;
    if(l==r)
    {
        seg[v]++;
        return;
    }
    int mid=(l+r)/2;
    update(v*2,l,mid,x);
    update(v*2+1,mid+1,r,x);
    seg[v]=seg[v*2]+seg[v*2+1];
}
ll query(int v,int l,int r,int x)
{
    if(r<x) return 0;
    if(l>=x) return seg[v];
    int mid=(l+r)/2;
    return query(v*2,l,mid,x)+query(v*2+1,mid+1,r,x);
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        res+=query(1,1,n,arr[i]);
        update(1,1,n,arr[i]);
        //cout<<res<<" ";
    }
    cout<<res;
}