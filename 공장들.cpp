# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,q;
vector<pair<ll,ll>> v[500010];
vector<pair<ll,ll>> v2[500010];
ll ch[500010];
ll num[500010];
ll dep[500010];
ll arr[500010];
ll brr[500010];
ll par[500010][25];
ll sten[500010];
ll dist[500010];
pll dp[500010];
ll cnt;
ll ans;
bool compare(ll a,ll b)
{
    return num[a]<num[b];
}
void go(ll x,ll p,ll d)
{
    num[x]=++cnt;
    ch[x]=1;
    dep[x]=d;
    par[x][0]=p;
    for(auto i:v[x])
    {
        if(!ch[i.second])
        {
            dist[i.second]=dist[x]+i.first;
            go(i.second,x,d+1);
        }
    }
}
void init()
{
    for(ll i=1;i<=20;i++)
        for(ll j=1;j<=n;j++)
            par[j][i]=par[par[j][i-1]][i-1];
}
ll LCA(ll x,ll y)
{
    if(dep[x]<dep[y]) swap(x,y);
    for(ll i=20;i>=0;i--)
        if(dep[x]-(1<<i)>=dep[y]) x=par[x][i];
    if(x==y) return x;
    for(ll i=20;i>=0;i--)
    {
        if(par[x][i]!=par[y][i])
        {
            x=par[x][i];
            y=par[y][i];
        }
    }
    return par[x][0];
}
void dfs1(ll x)
{
    //cout<<"| "<<x<<" "<<sten[x]<<'\n';
    if(sten[x]==1) dp[x]={0,1e18};
    else if(sten[x]==2) dp[x]={1e18,0};
    else dp[x]={1e18,1e18};
    for(auto i:v2[x])
    {
        dfs1(i.second);
        dp[x]={min(dp[x].first,dp[i.second].first+i.first),min(dp[x].second,dp[i.second].second+i.first)};
    }
}
void dfs2(ll x,pll num)
{
    num={min(num.first,dp[x].first),min(num.second,dp[x].second)};
    //cout<<num.first<<" "<<num.second<<'\n';
    ans=min(ans,num.first+num.second);
    for(auto i:v2[x])
        dfs2(i.second,{num.first+i.first,num.second+i.first});
}
int main()
{
    fastio;
    cin>>n>>q;
    for(ll i=1;i<=n-1;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        a++,b++;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    go(1,0,1);
    init();
    while(q--)
    {
        vector<ll> L;
        ll a,b;
        cin>>a>>b;
        for(ll i=1;i<=a;i++)
        {
            cin>>arr[i];
            arr[i]++;
            L.push_back(arr[i]);
            sten[arr[i]]=1;
        }
        for(ll i=1;i<=b;i++)
        {
            cin>>brr[i];
            brr[i]++;
            L.push_back(brr[i]);
            sten[brr[i]]=2;
        }
        sort(L.begin(),L.end(),compare);
        //cout<<dep[2]<<" "<<dep[3]<<'\n';
        ll sz=L.size();
        for(ll i=0;i<sz-1;i++)
            L.push_back(LCA(L[i],L[i+1]));
        sort(L.begin(),L.end(),compare);
        L.erase(unique(L.begin(),L.end()),L.end());
        for(ll i=0;i<L.size()-1;i++)
        {
            ll temp=LCA(L[i],L[i+1]);
            //cout<<temp<<" "<<L[i+1]<<'\n';
            v2[temp].push_back({dist[L[i+1]]-dist[temp],L[i+1]});
        }
        ans=1e18;
        dfs1(L[0]);
        dfs2(L[0],{(ll)1e18,(ll)1e18});
        cout<<ans<<'\n';
        for(auto i:L)
        {
            v2[i].clear();
            sten[i]=0;
        }
    }
}