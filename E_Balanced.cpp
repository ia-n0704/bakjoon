# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll arr[200010];

struct LazySeg
{
    ll tree[800010]={0};
    ll lazy[800010]={0};
    void init()
    {
        fill(tree,tree+n*+1ll,0);
        fill(lazy,lazy+n*4+1ll,0);
    }
    void prop(ll v,ll l,ll r)
    {
        if(!lazy[v]) return;
        tree[v]+=lazy[v]; 
        if(l!=r)
        {
            for(ll i=v*2;i<=v*2+1;i++)
            {
                lazy[i]+=lazy[v];
            }            
        }
        lazy[v]=0;
    }
    ll query(ll v,ll l,ll r,ll s)
    {
        prop(v,l,r);
        if(l>s || r<s)
            return 0;        
        if(l==r)
            return tree[v]; 
        ll mid=(l+r)/2;
        return query(v*2,l,mid,s)+query(v*2+1,mid+1,r,s);
    }
    void update(ll v,ll l,ll r,ll s,ll e,ll a)
    {
        prop(v,l,r);
        if(l>e || r<s)
            return;
        if(l>=s && r<=e)
        {
            lazy[v]=a;
            prop(v,l,r);
            return;
        }
        ll mid=(l+r)/2;
        update(v*2,l,mid,s,e,a);
        update(v*2+1,mid+1,r,s,e,a);
        tree[v]=tree[v*2]+tree[v*2+1];
    }
}Seg;

void sol()
{
    cin>>n;
    Seg.init();
    ll mx=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>arr[i];
        mx=max(mx,arr[i]);
    }
    for(ll i=1;i<=n;i++)
    {
        ll num=mx-arr[i];
        ll cur=i;
        if(cur!=1 && cur!=n)
        {
            Seg.update(1,1,n,cur,cur,n==3?num:(num*2));
            Seg.update(1,1,n,1,cur-2,n==3?0:num);
            Seg.update(1,1,n,cur+2,n,n==3?0:num);
        }
        else if(cur==1)
        {
            Seg.update(1,1,n,cur,cur,n==3?num:(num*2));
            Seg.update(1,1,n,cur+2,n-1,n==3?0:num);
        }
        else
        {
            Seg.update(1,1,n,cur,cur,n==3?num:(num*2));
            Seg.update(1,1,n,2,cur-2,n==3?0:num);
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<Seg.query(1,1,n,i)<<" ";
    }
    cout<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}