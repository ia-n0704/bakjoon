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
int n,m;
int X[10]={-1,-1,-1,0,1,1,1,0};
int Y[10]={-1,0,1,1,1,0,-1,-1};
ll c[500][500];
ll dist[500][500];
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>c[i][j];
            if(c[i][j]==-2) c[i][j]=0;
        }
    }
    queue<pii> q;
    for(int i=1;i<=n;i++)
        if(c[i][1]!=-1) q.push({i,1});
    for(int i=1;i<=m;i++)
        if(c[n][i]!=-1) q.push({n,i});
    ll res=1e18;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dist[i][j]=1e18;
    priority_queue<pair<ll,pii>,vector<pair<ll,pii>>,greater<pair<ll,pii>>> pq;
    while(!q.empty())
    {
        pii st=q.front();
        q.pop();
        pq.push({c[st.fi][st.se],st});
        dist[st.fi][st.se]=c[st.fi][st.se];
    }
    while(!pq.empty())
    {
        auto a=pq.top();
        pq.pop();
        ll co=a.fi;
        int x=a.se.fi;
        int y=a.se.se;
        if(dist[x][y]<co) continue;
        for(int i=0;i<8;i++)
        {
            pii nx={x+X[i],y+Y[i]};
            if(nx.fi<1 || nx.fi>n || nx.se<1 || nx.se>m) continue;
            if(c[nx.fi][nx.se]==-1) continue;
            ll nx_co=co+c[nx.fi][nx.se];
            if(nx_co<dist[nx.fi][nx.se])
            {
                dist[nx.fi][nx.se]=nx_co;
                pq.push({nx_co,nx});
            }
        }
    }
    for(int i=1;i<=m;i++)
        res=min(res,dist[1][i]);
    for(int i=1;i<=n;i++)
        res=min(res,dist[i][m]);
    if(res==1e18) res=-1;
    cout<<res;
}
