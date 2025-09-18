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
ll n,l;
ll x[210];
ll t[210];
ll dp[210][210][210][3];
int main()
{
    fastio;
    cin>>n>>l;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=n;i++) cin>>t[i];
    x[n+1]=l;
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=n+1;j++)
            for(int k=0;k<=n+1;k++)
                for(int r=1;r<=2;r++)
                    dp[i][j][k][r]=1e18;
    dp[0][n+1][0][1]=dp[0][n+1][0][2]=0;
    ll res=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=n+1;j>i;j--)
        {
            for(ll k=0;k<=n-j+1+i;k++)
            {
                ll &ttt=dp[i][j][k][1];
                if(i>0) ttt=min(ttt,dp[i-1][j][k][1]+x[i]-x[i-1]);
                if(i>0) ttt=min(ttt,dp[i-1][j][k][2]+x[i]+l-x[j]);
                if(k>0 && i>0 && dp[i-1][j][k-1][1]+x[i]-x[i-1]<=t[i]) ttt=min(ttt,dp[i-1][j][k-1][1]+x[i]-x[i-1]);
                if(k>0 && i>0 && dp[i-1][j][k-1][2]+x[i]+l-x[j]<=t[i]) ttt=min(ttt,dp[i-1][j][k-1][2]+x[i]+l-x[j]);
                if(ttt<1e18) res=max(res,k);
                
                ll &tt=dp[i][j][k][2];
                if(j<=n) tt=min(tt,dp[i][j+1][k][2]+x[j+1]-x[j]);
                if(j<=n) tt=min(tt,dp[i][j+1][k][1]+x[i]+l-x[j]);
                if(k>0 && j<=n && dp[i][j+1][k-1][2]+x[j+1]-x[j]<=t[j]) tt=min(tt,dp[i][j+1][k-1][2]+x[j+1]-x[j]);
                if(k>0 && j<=n && dp[i][j+1][k-1][1]+x[i]+l-x[j]<=t[j]) tt=min(tt,dp[i][j+1][k-1][1]+x[i]+l-x[j]);
                if(tt<1e18) res=max(res,k);  
                //printf("dp[%d][%d][%d]={%d,%d}\n",i,j,k,ttt,tt);
            }
        }
    }
    cout<<res;
}
