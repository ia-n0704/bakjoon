# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin,(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n,m;
int seg[400010];
int lazy[800010];
void prop(int v,int sz)
{
    if(lazy[v])
    {
        lazy[v]=0;
        seg[v]=sz-seg[v];
        lazy[v*2]^=1;
        lazy[v*2+1]^=1;
    }
}
void update(int v,int l,int r,int s,int e)
{
    prop(v,r-l+1);
    if(l>e || r<s) return;
    if(l>=s && r<=e)
    {
        lazy[v]^=1;
        prop(v,r-l+1);
        return;
    }
    int mid=(l+r)/2;
    update(v*2,l,mid,s,e);
    update(v*2+1,mid+1,r,s,e);
    seg[v]=seg[v*2]+seg[v*2+1];
}
int query(int v,int l,int r,int s,int e)
{
    prop(v,r-l+1);
    if(l>e || r<s) return 0;
    if(l>=s && r<=e) return seg[v];
    int mid=(l+r)/2;
    return query(v*2,l,mid,s,e)+query(v*2+1,mid+1,r,s,e);
}
int main()
{
    fastio;
    cin>>n>>m;
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0)
            update(1,1,n,b,c);
        else
        {
            cout<<query(1,1,n,b,c)<<'\n';
        }
    }
}
