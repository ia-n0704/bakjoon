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
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<ll> vll;
const ll mod=998'244'353;
const ll MOD=1e9+7;
struct UF
{
    vector<ll> par;
    void _init(ll n)
    {
        par.resize(n+1);
        iota(all(par),0);
    }
    ll _find(ll x)
    {
        if(par[x]==x) return x;
        return par[x]=_find(par[x]);
    }
    void _merge(ll x,ll y)
    {
        ll fx=_find(x),fy=_find(y);
        if(fx==fy) return;
        if(fx>fy) swap(fx,fy);
        par[fy]=fx; 
    }
};
struct MaxSeg
{
    vector<ll> arr;
    vector<ll> seg;
    ll seg_init(ll v,ll l,ll r)
    {
        if(l==r)
        {
            seg[v]=arr[l];
            return seg[v];
        }
        ll mid=(l+r)/2;
        return seg[v]=max(seg_init(v*2,l,mid),seg_init(v*2+1,mid+1,r));
    }
    void _init(ll n,vector<ll> t)
    {
        arr.resize(n+10);
        seg.resize(n*4+10);
        for(ll i=0;i<t.size();i++)
            arr[i]=t[i];
        seg_init(1,0,n-1);
    }
    void update(ll v,ll l,ll r,ll idx,ll num)
    {
        if(l>idx || r<idx) return;
        if(l==r)
        {
            seg[v]=num;
            return;
        }
        ll mid=(l+r)/2;
        update(v*2,l,mid,idx,num);
        update(v*2+1,mid+1,r,idx,num);
        seg[v]=max(seg[v*2],seg[v*2+1]);
    }
    ll query(ll v,ll l,ll r,ll s,ll e)
    {
        if(l>e || r<s) return -1e18;
        if(l>=s && r<=e) return seg[v];
        ll mid=(l+r)/2;
        return max(query(v*2,l,mid,s,e),query(v*2+1,mid+1,r,s,e));
    }
};
struct MinSeg
{
    vector<ll> arr;
    vector<ll> seg;
    ll seg_init(ll v,ll l,ll r)
    {
        if(l==r)
        {
            seg[v]=arr[l];
            return seg[v];
        }
        ll mid=(l+r)/2;
        return seg[v]=min(seg_init(v*2,l,mid),seg_init(v*2+1,mid+1,r));
    }
    void _init(ll n,vector<ll> t)
    {
        arr.resize(n+10);
        seg.resize(n*4+10);
        for(ll i=0;i<t.size();i++)
            arr[i]=t[i];
        seg_init(1,0,n-1);
    }
    void update(ll v,ll l,ll r,ll idx,ll num)
    {
        if(l>idx || r<idx) return;
        if(l==r)
        {
            seg[v]=num;
            return;
        }
        ll mid=(l+r)/2;
        update(v*2,l,mid,idx,num);
        update(v*2+1,mid+1,r,idx,num);
        seg[v]=min(seg[v*2],seg[v*2+1]);
    }
    ll query(ll v,ll l,ll r,ll s,ll e)
    {
        if(l>e || r<s) return 1e18;
        if(l>=s && r<=e) return seg[v];
        ll mid=(l+r)/2;
        return min(query(v*2,l,mid,s,e),query(v*2+1,mid+1,r,s,e));
    }
};
struct SumSeg
{
    vector<ll> arr;
    vector<ll> seg;
    ll seg_init(ll v,ll l,ll r)
    {
        if(l==r)
        {
            seg[v]=arr[l];
            return seg[v];
        }
        ll mid=(l+r)/2;
        return seg[v]=seg_init(v*2,l,mid)+seg_init(v*2+1,mid+1,r);
    }
    void _init(ll n,vector<ll> t)
    {
        arr.resize(n+10);
        seg.resize(n*4+10);
        for(ll i=0;i<t.size();i++)
            arr[i]=t[i];
        seg_init(1,0,n-1);
    }
    void update(ll v,ll l,ll r,ll idx,ll num)
    {
        if(l>idx || r<idx) return;
        if(l==r)
        {
            seg[v]=num;
            return;
        }
        ll mid=(l+r)/2;
        update(v*2,l,mid,idx,num);
        update(v*2+1,mid+1,r,idx,num);
        seg[v]=seg[v*2]+seg[v*2+1];
    }
    ll query(ll v,ll l,ll r,ll s,ll e)
    {
        if(l>e || r<s) return 0ll;
        if(l>=s && r<=e) return seg[v];
        ll mid=(l+r)/2;
        return query(v*2,l,mid,s,e)+query(v*2+1,mid+1,r,s,e);
    }
};
ll n,m;
vector<pair<pii,ll>> v[300010];
ll dist[300010],dist2[300010];
ll ch[300010];
pair<pii,ll> g[300010];
int main()
{
    fastio;
    cin>>n>>m;
    for(ll i=1;i<=m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({{b,c},i});
        v[b].push_back({{a,c},i});
        g[i]={{a,b},c};
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,1});
    fill(dist,dist+n+1,1e18);
    while(!pq.empty())
    {
        auto a=pq.top();
        pq.pop();
        ll cur=a.se;
        ll co=a.fi;
        if(co>=dist[cur]) continue;
        dist[cur]=co;
        for(auto i:v[cur])
        {
            ll nx=i.fi.fi;
            ll nco=co+i.fi.se;
            if(nco<dist[nx])
                pq.push({nco,nx});
        }
    }
    if(dist[n]>=1e18)
    {
        cout<<-1;
        return 0;
    }
    ll temp=dist[n];
    ll cur=n;
    while(cur!=1)
    {
        for(auto i:v[cur])
        {
            if(temp-i.fi.se==dist[i.fi.fi])
            {
                cur=i.fi.fi;
                temp=dist[i.fi.fi];
                ch[i.se]=1;
                break;
            }
        }
    }

    pq.push({0,n});
    fill(dist2,dist2+n+1,1e18);
    while(!pq.empty())
    {
        auto a=pq.top();
        pq.pop();
        ll cur=a.se;
        ll co=a.fi;
        if(co>=dist2[cur]) continue;
        dist2[cur]=co;
        for(auto i:v[cur])
        {
            ll nx=i.fi.fi;
            ll nco=co+i.fi.se;
            if(nco<dist2[nx])
                pq.push({nco,nx});
        }
    }
    ll mn=1e18;
    for(ll i=1;i<=m;i++)
    {
        if(ch[i]) continue;
        mn=min(mn,g[i].se+dist[g[i].fi.fi]+dist2[g[i].fi.se]);
    }
    if(mn+dist[n]>=1e18)
    {
        cout<<-1;
        return 0;
    }
    cout<<mn+dist[n];
}
