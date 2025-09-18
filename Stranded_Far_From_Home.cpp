# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
ll n,m;
vector<pii> v;
ll arr[200010];
ll par[200010];
set<ll> s[200010];
ll sz[200010];
ll _find(ll x)
{
    if(par[x]==x) return x;
    return par[x]=_find(par[x]);
}
void _merge(ll x,ll y)
{
    ll fx=_find(x),fy=_find(y);
    if(fx==fy) return;
    //cout<<"| "<<fx<<" "<<fy<<'\n';
    if(sz[fx]<arr[y])
    {
        par[fx]=fy;
        sz[fy]+=sz[fx];
    }
    else
    {
        if(s[fx].size()>s[fy].size()) swap(fx,fy);
        for(auto i:s[fx]) s[fy].insert(i);
        par[fx]=fy;
        sz[fy]+=sz[fx];
    }
}
bool compare(pii x,pii y)
{
    if(sz[x.fi]==sz[y.fi]) return sz[x.se]<sz[y.se];
    return sz[x.fi]<sz[y.fi];
}
int main()
{
    fastio;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>arr[i];
        sz[i]=arr[i];
    }
    for(ll i=1;i<=m;i++)
    {
        ll a,b;
        cin>>a>>b;
        if(sz[a]<sz[b]) swap(a,b);
        v.push_back({a,b});
    }
    sort(all(v),compare);
    for(ll i=1;i<=n;i++)
    {
        par[i]=i;
        s[i].insert(i);
    }
    for(ll i=0;i<v.size();i++)
    {
        ll x=v[i].se,y=v[i].fi;
        //cout<<x<<" "<<y<<'\n';
        _merge(x,y);
    }
    ll st=_find(1);
    for(ll i=1;i<=n;i++)
    {
        if(s[st].count(i)) cout<<1;
        else cout<<0;
    }
}
