# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,q;
ll seg[8000010];
void update(int v,int l,int r,int x,int co)
{
    if(l>x || r<x) return;
    if(l==r) 
    {
        seg[v]+=co;
        return;
    }
    int mid=(l+r)/2;
    update(v*2,l,mid,x,co);
    update(v*2+1,mid+1,r,x,co);
    seg[v]=seg[v*2]+seg[v*2+1];
}
ll query(int v,int l,int r,int st,int en)
{
    if(l>en || r<st) return 0;
    if(st<=l && en>=r)
        return seg[v];
    int mid=(l+r)/2;
    return query(v*2,l,mid,st,en)+query(v*2+1,mid+1,r,st,en);
}
int main()
{
    fastio;
    cin>>n>>q;
    while(q--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
            update(1,1,n,b,c);
        else cout<<query(1,1,n,b,c)<<'\n';
    }
}