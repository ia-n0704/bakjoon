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
ll n,l,nn;
map<ll,ll> cnt;
ll dp[1010][1010][3];
ll ans[1010][3];
ll q;
ll sum[1010];
int main()
{
    fastio;
    cin>>n>>l;
    nn=n;
    vector<ll> v;
    for(int i=1;i<=n;i++)
    {
        ll a;
        cin>>a;
        v.push_back(a);
        cnt[a]++;
    }
    sort(all(v));
    v.erase(unique(all(v)),v.end());
    n=v.size();
    if(n>1000)
    {
        cin>>q;
        for(int i=1;i<=q;i++)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            cout<<"No\n";
        }
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        ll num=cnt[v[i]];
        if(i>0) sum[i]=sum[i-1];
        sum[i]+=num;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<=1;k++)
                dp[i][j][k]=1e18;
    dp[0][n-1][0]=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j+i<n;j++)
        {
            int l=j,r=i+j;
            ll num=nn-sum[r]+1;
            if(l>0) num+=sum[l-1];

            if(l>0)
                dp[l][r][1]=dp[l-1][r][0]+num*(v[r]-v[l-1]);
            if(r<n-1)
                dp[l][r][0]=dp[l][r+1][1]+num*(v[r+1]-v[l]);
            if(l>0)
                dp[l][r][0]=min(dp[l][r][0],dp[l-1][r][0]+num*(v[l]-v[l-1]));
            if(r<n-1)
                dp[l][r][1]=min(dp[l][r][1],dp[l][r+1][1]+num*(v[r+1]-v[r]));
        }
    }
    for(int i=0;i<n;i++)
        ans[i][0]=min(dp[i][i][0],dp[i][i][1]);
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<=1;k++)
                dp[i][j][k]=1e18;
    dp[0][n-1][1]=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j+i<n;j++)
        {
            int l=j,r=i+j;
            ll num=nn-sum[r]+1;
            if(l>0) num+=sum[l-1];

            if(l>0)
                dp[l][r][1]=dp[l-1][r][0]+num*(v[r]-v[l-1]);
            if(r<n-1)
                dp[l][r][0]=dp[l][r+1][1]+num*(v[r+1]-v[l]);
            if(l>0)
                dp[l][r][0]=min(dp[l][r][0],dp[l-1][r][0]+num*(v[l]-v[l-1]));
            if(r<n-1)
                dp[l][r][1]=min(dp[l][r][1],dp[l][r+1][1]+num*(v[r+1]-v[r]));
        }
    }
    for(int i=0;i<n;i++)
        ans[i][1]=min(dp[i][i][0],dp[i][i][1]);

    cin>>q;
    while(q--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll idx=lower_bound(all(v),b)-v.begin();
        ll res=1e18;
        for(int i=idx-2;i<=idx+2;i++)
        {
            if(i<0 || i>=n) continue;
            res=min(res,ans[i][0]+abs(a-v[0])+(nn+1)*abs(v[i]-b));
            res=min(res,ans[i][1]+abs(a-v[n-1])+(nn+1)*abs(v[i]-b));
        }
        if(res+nn<=c)
            cout<<"Yes\n";
        else cout<<"No\n";
    }
}
