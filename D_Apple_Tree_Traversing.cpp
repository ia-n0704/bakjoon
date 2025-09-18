# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
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
int n;
vector<int> v[200010];
int ch[200010];
int check[200010];
int dep[200010];
int par[200010];
queue<int> q;
vector<pair<ll,pll>> ans;
int mx,num;
void dfs(int x,int cnt,int p)
{
    dep[x]=cnt;
    for(auto i:v[x])
    {
        if(i==p) continue;
        par[i]=x;
        dfs(i,cnt+1,x);
    }
}
void _find(int x,int cnt,int p)
{
    if(cnt>mx)
    {
        mx=cnt;
        num=x;
    }
    else if(cnt==mx)
        num=max(num,x);
    for(auto i:v[x])
    {
        if(ch[i]!=1 && i!=p)
            _find(i,cnt+1,x);
    }
}
void go(int x)
{
    mx=0,num=x;
    _find(x,0,0);
    int a=num;
    mx=0,num=a;
    _find(a,0,0);
    int b=num;
    int aa=a,bb=b;
    if(dep[a]>dep[b]) swap(a,b);
    int cnt=0;
    while(dep[a]<dep[b])
    {      
        for(auto i:v[b])
            if(ch[i]==0 && i!=par[b]) q.push(i);
        ch[b]=1;
        b=par[b];
        cnt++;
    }
    while(a!=b)
    {
        for(auto i:v[a])
            if(ch[i]==0 && i!=par[a]) q.push(i);
        for(auto i:v[b])
            if(ch[i]==0 && i!=par[b]) q.push(i);
        ch[a]=ch[b]=1;
        a=par[a];
        b=par[b];
        cnt+=2;
    }
    cnt++;
    ch[a]=1;
    for(auto i:v[b])
        if(ch[i]==0) q.push(i);
    ans.push_back({cnt,{max(aa,bb),min(aa,bb)}});
}
int up(int x)
{
    while(par[x] && ch[par[x]]==0)
        x=par[x];
    return x;
}
void sol()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,1,0);
    q.push(1);
    while(!q.empty())
    {
        int t=up(q.front());
        q.pop();
        if(ch[t]) continue;
        go(t);
    }
    sort(all(ans));
    reverse(all(ans));
    for(auto i:ans)
    {
        cout<<i.fi<<" "<<i.se.fi<<" "<<i.se.se<<" ";
    }
    cout<<"\n";
    ans.clear();
    for(int i=1;i<=n;i++)
    {
        dep[i]=par[i]=ch[i]=check[i]=0;
        v[i].clear();
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}