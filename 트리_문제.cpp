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
const ll mod=998'244'353;
const ll MOD=1e9+7;
struct UF
{
    vector<int> par;
    void _init(int n)
    {
        par.resize(n+1);
        iota(all(par),0);
    }
    int _find(int x)
    {
        if(par[x]==x) return x;
        return par[x]=_find(par[x]);
    }
    void _merge(int x,int y)
    {
        int fx=_find(x),fy=_find(y);
        if(fx==fy) return;
        if(fx>fy) swap(fx,fy);
        par[fy]=fx; 
    }
};
struct MaxSeg
{
    vector<ll> arr;
    vector<ll> seg;
    ll seg_init(int v,int l,int r)
    {
        if(l==r)
        {
            seg[v]=arr[l];
            return seg[v];
        }
        int mid=(l+r)/2;
        return seg[v]=max(seg_init(v*2,l,mid),seg_init(v*2+1,mid+1,r));
    }
    void _init(int n,vector<ll> t)
    {
        arr.resize(n+10);
        seg.resize(n*4+10);
        for(int i=0;i<t.size();i++)
            arr[i]=t[i];
        seg_init(1,0,n-1);
    }
    void update(int v,int l,int r,int idx,ll num)
    {
        if(l>idx || r<idx) return;
        if(l==r)
        {
            seg[v]=num;
            return;
        }
        int mid=(l+r)/2;
        update(v*2,l,mid,idx,num);
        update(v*2+1,mid+1,r,idx,num);
        seg[v]=max(seg[v*2],seg[v*2+1]);
    }
    ll query(int v,int l,int r,int s,int e)
    {
        if(l>e || r<s) return -1e18;
        if(l>=s && r<=e) return seg[v];
        int mid=(l+r)/2;
        return max(query(v*2,l,mid,s,e),query(v*2+1,mid+1,r,s,e));
    }
};
struct MinSeg
{
    vector<ll> arr;
    vector<ll> seg;
    ll seg_init(int v,int l,int r)
    {
        if(l==r)
        {
            seg[v]=arr[l];
            return seg[v];
        }
        int mid=(l+r)/2;
        return seg[v]=min(seg_init(v*2,l,mid),seg_init(v*2+1,mid+1,r));
    }
    void _init(int n,vector<ll> t)
    {
        arr.resize(n+10);
        seg.resize(n*4+10);
        for(int i=0;i<t.size();i++)
            arr[i]=t[i];
        seg_init(1,0,n-1);
    }
    void update(int v,int l,int r,int idx,ll num)
    {
        if(l>idx || r<idx) return;
        if(l==r)
        {
            seg[v]=num;
            return;
        }
        int mid=(l+r)/2;
        update(v*2,l,mid,idx,num);
        update(v*2+1,mid+1,r,idx,num);
        seg[v]=min(seg[v*2],seg[v*2+1]);
    }
    ll query(int v,int l,int r,int s,int e)
    {
        if(l>e || r<s) return 1e18;
        if(l>=s && r<=e) return seg[v];
        int mid=(l+r)/2;
        return min(query(v*2,l,mid,s,e),query(v*2+1,mid+1,r,s,e));
    }
};
struct SumSeg
{
    vector<ll> arr;
    vector<ll> seg;
    ll seg_init(int v,int l,int r)
    {
        if(l==r)
        {
            seg[v]=arr[l];
            return seg[v];
        }
        int mid=(l+r)/2;
        return seg[v]=seg_init(v*2,l,mid)+seg_init(v*2+1,mid+1,r);
    }
    void _init(int n,vector<ll> t)
    {
        arr.resize(n+10);
        seg.resize(n*4+10);
        for(int i=0;i<t.size();i++)
            arr[i]=t[i];
        seg_init(1,0,n-1);
    }
    void update(int v,int l,int r,int idx,ll num)
    {
        if(l>idx || r<idx) return;
        if(l==r)
        {
            seg[v]=num;
            return;
        }
        int mid=(l+r)/2;
        update(v*2,l,mid,idx,num);
        update(v*2+1,mid+1,r,idx,num);
        seg[v]=seg[v*2]+seg[v*2+1];
    }
    ll query(int v,int l,int r,int s,int e)
    {
        if(l>e || r<s) return 0ll;
        if(l>=s && r<=e) return seg[v];
        int mid=(l+r)/2;
        return query(v*2,l,mid,s,e)+query(v*2+1,mid+1,r,s,e);
    }
};
int n,q;
vector<pll> v[100010];
ll sz[100010];
ll ch[100010];
ll new_par[100010];
ll arr[100010];
pll par[22][100010];
int dep[100010];
void dfs(int cur,int p,int cnt)
{
    dep[cur]=cnt;
    for(auto i:v[cur])
    {
        if(i.fi==p) continue;
        par[0][i.fi]={cur,i.se};
        dfs(i.fi,cur,cnt+1);
    }
}
void init()
{
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=n;j++)
        {
            par[i][j].fi=par[i-1][par[i-1][j].fi].fi;
            par[i][j].se=par[i-1][j].se+par[i-1][par[i-1][j].fi].se;
        }
    }
}
ll dist(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    ll res=0;
    for(int i=20;i>=0;i--)
    {
        if(dep[par[i][x].fi]>=dep[y])
        {
            res+=par[i][x].se;
            x=par[i][x].fi;
        }
    }
    for(int i=20;i>=0;i--)
    {
        if(par[i][x].fi!=par[i][y].fi)
        {
            res+=par[i][x].se+par[i][y].se;
            x=par[i][x].fi;
            y=par[i][y].fi;
        }
    }
    if(x!=y)
        res+=par[0][x].se+par[0][y].se;
    return res;
}
void get_size(int cur,int p)
{
    sz[cur]=1;
    for(auto i:v[cur])
    {
        if(i.fi==p || ch[i.fi]) continue;
        get_size(i.fi,cur);
        sz[cur]+=sz[i.fi];
    }
}
int get_cent(int cur,int p,int total)
{
    for(auto i:v[cur])
    {
        if(i.fi==p || ch[i.fi]) continue;
        if(sz[i.fi]*2>total) return get_cent(i.fi,cur,total);
    }
    return cur;
}
void make_tree(int cur,int p)
{
    get_size(cur,0);
    int c=get_cent(cur,0,sz[cur]);
    ch[c]=1;
    new_par[c]=p;
    for(auto i:v[c])
    {
        if(ch[i.fi]) continue;
        make_tree(i.fi,c);
    }
}
ll dp[100010];
ll blue_sz[100010];
map<int,ll> m[100010];
void update(int cur)
{
    if(arr[cur]) return;
    int t=new_par[cur],prev=cur;
    arr[cur]=1;
    blue_sz[cur]++;
    while(t)
    {
        ll d=dist(t,cur);
        dp[t]+=d;
        m[t][prev]+=d;
        blue_sz[t]++;
        prev=t;
        t=new_par[t];
    }
}
ll query(int cur)
{
    int t=new_par[cur],prev=cur;
    ll res=dp[cur];
    while(t)
    {
        ll d=dist(t,cur);
        res+=dp[t]-m[t][prev]+(blue_sz[t]-blue_sz[prev])*d;
        prev=t;
        t=new_par[t];
    }
    return res;
}
int main()
{
    fastio;
    cin>>n>>q;
    for(int i=1;i<n;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        a++,b++;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dfs(1,0,1);
    init();
    make_tree(1,0);
    for(int i=1;i<=q;i++)
    {
        int a,b;
        cin>>a>>b;
        b++;
        if(a==1) update(b);
        else cout<<query(b)<<'\n';
    }
}
