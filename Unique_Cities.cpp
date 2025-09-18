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
vector<int> g[200010];
int c[200010];
int dep[200010];
int dep_st[200010];
int dep_en[200010];
int st,en;
int sz[200010];
vector<int> v[200010];
int res[200010];
stack<pii> s;
int ch[200010];
int ans_st[200010],ans_en[200010];
bool compare(int a,int b)
{
    return sz[a]>sz[b];
}
void dfs(int x,int p,int *d,int dist)
{
    d[x]=dist;
    for(auto i:g[x])
    {
        if(i==p) continue;
        dfs(i,x,d,dist+1);
    }
}
void get_sz(int x,int p,int *arr)
{
    for(auto i:g[x])
    {
        if(i==p) continue;
        v[x].push_back(i);
        get_sz(i,x,arr);
        arr[x]=max(arr[x],arr[i]+1);
    }
}
void go(int x,int p,int *d,int *ans)
{
    if(v[x].size()==1)
    {
        if((s.empty() || s.top().fi<d[x]) && ch[c[x]]==0)
        {
            ch[c[x]]=1;
            s.push({d[x],c[x]});
        }
        go(v[x][0],x,d,ans);
        while(!s.empty() && s.top().fi>=d[x]-sz[x])
        {
            ch[s.top().se]=0;
            s.pop();
        }
    }
    else if(v[x].size()>1)
    {
        while(!s.empty() && s.top().fi>=d[x]-sz[v[x][1]]-1)
        {
            ch[s.top().se]=0;
            s.pop();
        }
        if((s.empty() || s.top().fi<d[x]) && ch[c[x]]==0)
        {
            ch[c[x]]=1;
            s.push({d[x],c[x]});
        }
        go(v[x][0],x,d,ans);
        while(!s.empty() && s.top().fi>=d[x]-sz[x])
        {
            ch[s.top().se]=0;
            s.pop();
        }
        for(int i=1;i<v[x].size();i++)
        {
            int nx=v[x][i];
            if((s.empty() || s.top().fi<d[x]) && ch[c[x]]==0)
            {
                ch[c[x]]=1;
                s.push({d[x],c[x]});
            }
            go(nx,x,d,ans);
        }
        while(!s.empty() && s.top().fi>=d[x]-sz[x])
        {
            ch[s.top().se]=0;
            s.pop();
        }
    }
    ans[x]=s.size();
}
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    dfs(1,0,dep,0);
    for(int i=1;i<=n;i++) if(dep[i]>dep[st]) st=i;
    dfs(st,0,dep_st,0);
    for(int i=1;i<=n;i++) if(dep_st[i]>dep_st[en]) en=i;
    dfs(en,0,dep_en,0);

    get_sz(st,0,sz);
    for(int i=1;i<=n;i++)
        sort(all(v[i]),compare);
    go(st,0,dep_st,ans_st);
    
    for(int i=1;i<=n;i++)
    {
        sz[i]=0;
        ch[i]=0;
        v[i].clear();
    }
    while(!s.empty()) s.pop();
    get_sz(en,0,sz);
    for(int i=1;i<=n;i++)
        sort(all(v[i]),compare);
    go(en,0,dep_en,ans_en);

    for(int i=1;i<=n;i++)
        cout<<max(ans_st[i],ans_en[i])<<'\n';
}
