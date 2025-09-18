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
ll sp[200010][22];
ll n;
ll dp[200010];
ll p[200010];
ll dep[200010];
ll rev_p[200010];
vector<ll> v[200010];
vector<ll> par;
void _init(ll n)
{
    par.resize(n+1);
    iota(all(par),0);
}
int _find(ll x)
{
    if(par[x]==x) return x;
    return par[x]=_find(par[x]);
}
void _merge(ll x,ll y,ll num)
{
    ll fx=_find(x),fy=_find(y);
    if(fx==fy) return;
    if(fx<fy) swap(fx,fy);
    par[fy]=fx; 
    dp[fx]=max(dp[fx],num);
}
void dfs(ll x,ll k,ll cnt)
{
    dep[x]=cnt;
    for(auto i:v[x])
    {
        if(i==k) continue;
        sp[i][0]=x;
        dfs(i,x,cnt+1);
    }
}
void par_init()
{
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n;j++)
            sp[j][i]=sp[sp[j][i-1]][i-1];
}
ll dist(ll x,ll y)
{
    ll res=0;
    if(dep[x]<dep[y]) swap(x,y);
    for(ll i=20;i>=0;i--)
    {
        if(dep[x]-(1<<i)>=dep[y])
        {
            res+=(1ll<<i);
            x=sp[x][i];
        }
    }
    for(ll i=20;i>=0;i--)
    {
        if(sp[x][i]!=sp[y][i])
        {
            x=sp[x][i];
            y=sp[y][i];
            res+=2*(1<<i);
        }
    }
    if(x!=y)
        res+=2;
    return res;
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        rev_p[p[i]]=i;
    }
    for(int i=1;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        v[p[a]].push_back(p[b]);
        v[p[b]].push_back(p[a]);
    }
    dfs(n,0,1);
    par_init();
    _init(n);
    fill(dp,dp+n+1,-1);
    for(int i=1;i<=n;i++)
    {
        dp[i]=0;
        for(auto j:v[i])
        {
            ll idx=_find(j);
            if(dp[idx]!=-1)
            {
                ll num=dist(idx,i)+dp[idx];
                _merge(i,idx,num);
            }
        }
        //cout<<dp[i]<<" ";
    }
    cout<<dp[n];
}
