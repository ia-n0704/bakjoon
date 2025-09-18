# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,q1,q2;
ll arr[1000010];
ll seg[4000010];
ll lazy[8000010];
void prop(int v,int l,int r)
{
    seg[v]+=lazy[v]*(r-l+1);
    if(l==r)
    {
        lazy[v]=0;
        return;
    }
    for(auto i:{v*2,v*2+1})
        lazy[i]+=lazy[v];
    lazy[v]=0;
}
void update(int v,int l,int r,int s,int e,ll num)
{
    prop(v,l,r);
    if(r<s || l>e) return;
    if(l>=s && r<=e)
    {
        lazy[v]+=num;
        prop(v,l,r);
        return;
    }
    int mid=(l+r)/2;
    update(v*2,l,mid,s,e,num);
    update(v*2+1,mid+1,r,s,e,num);
    seg[v]=seg[v*2]+seg[v*2+1];
}
ll query(int v,int l,int r,int s,int e)
{
    prop(v,l,r);
    if(r<s || l>e) return 0;
    if(l>=s && r<=e)
        return seg[v];
    int mid=(l+r)/2;
    return query(v*2,l,mid,s,e)+query(v*2+1,mid+1,r,s,e);
}
int main()
{
    fastio;
    cin>>n>>q1>>q2;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        update(1,1,n,i,i,arr[i]);
    }
    for(int i=1;i<=q1+q2;i++)
    {
        int c;
        cin>>c;
        if(c==1)
        {
            int x,y;
            cin>>x>>y;
            cout<<query(1,1,n,x,y)<<'\n';
        }
        else
        {
            ll x,y,z;
            cin>>x>>y>>z;
            update(1,1,n,x,y,z);
        }
    }
}