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
struct node
{
    ll co,cur,visit,ch;
    ll t;
    bool operator<(const node &x) const{
        return co<x.co;
    }
};
ll n,m;
vector<ll> v[501];
pair<pll,pll> graph[100010];
ll dist[501][2];
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        graph[i]={{a,b},{c,d}};
        graph[m+i]={{2*n-a,2*n-b},{c,d}};
        v[a].push_back(i);
        v[b].push_back(i);
        v[n*2-a].push_back(m+i);
        v[n*2-b].push_back(m+i);
    }
    priority_queue<node> pq;
    pq.push({0,1,0,0,(ll)1e18});
    for(int i=1;i<=2*n;i++)
        dist[i][0]=dist[i][1]=1e18;
    while(!pq.empty())
    {
        auto a=pq.top();
        pq.pop();
        ll co=a.co;
        ll cur=a.cur;
        ll visit=a.visit;
        ll ch=a.ch;
        ll t=a.t;
        cout<<co<<" "<<cur<<" "<<t<<'\n';
        if(dist[cur][ch]<co) continue;
        dist[cur][ch]=co;
        for(auto i:v[cur])
        {
            ll x=graph[i].fi.fi;
            ll y=graph[i].fi.se;
            if(t==i || i-m==t) swap(x,y);
            ll nx_co=graph[i].se.fi;
            ll rev_co=graph[i].se.se;
            ll temp=visit;
            if(x==cur)
            {
                if(y>=n) temp=1;
                if(dist[y][ch]>co+nx_co)
                    pq.push({co+nx_co,y,temp,ch,t});
            }
            else
            {
                if(!ch && !visit)
                {
                    if(x<=n && y<=n)
                    {
                        if(x>=n) temp=1; 
                        if(dist[x][1]>co+rev_co+nx_co)
                            pq.push({co+rev_co+nx_co,x,temp,1,i});
                    }
                }
            }
        }
    }
    ll res=min(dist[2*n-1][0],dist[2*n-1][1]);
    if(res==1e18) res=-1;
    cout<<res;
}
