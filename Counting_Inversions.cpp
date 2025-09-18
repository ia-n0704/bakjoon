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
int arr[1000010];
int seg[4000010];
void update(int v,int l,int r,int idx)
{
    if(l>idx || r<idx) return;
    if(l==r)
    {
        seg[v]=1;
        return;
    }
    int mid=(l+r)/2;
    update(v*2,l,mid,idx);
    update(v*2+1,mid+1,r,idx);
    seg[v]=seg[v*2]+seg[v*2+1];
}
ll query(int v,int l,int r,int s,int e)
{
    if(l>e || r<s) return 0;
    if(l>=s && r<=e) return seg[v];
    int mid=(l+r)/2;
    return query(v*2,l,mid,s,e)+query(v*2+1,mid+1,r,s,e);
}
int main()
{
    fastio;
    cin>>n;
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        res+=query(1,1,n,arr[i],n);
        update(1,1,n,arr[i]);
    }
    cout<<res;
}