# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin,(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
int q;
pll sp[100010][20];
vector<pll> v[100010];
int ch[100010];
int dep[100010];
void dfs(int x,int cnt)
{
    ch[x]=1;
    dep[x]=cnt;
    for(auto i:v[x])
    {
        if(ch[i.fi]) continue;
        sp[i.fi][0]={x,i.se};
        dfs(i.fi,cnt+1);
    }
}
void init()
{
    for(int i=1;i<=18;i++)
        for(int j=1;j<=n;j++)
            sp[j][i]={sp[sp[j][i-1].fi][i-1].first,sp[j][i-1].se+sp[sp[j][i-1].fi][i-1].se};
}
ll query(int a,int b)
{
    ll res=0;
    if(dep[a]<dep[b]) swap(a,b);
    for(int i=18;i>=0;i--)
    {
        if(dep[sp[a][i].fi]>=dep[b])
        {
            res+=sp[a][i].se;
            a=sp[a][i].fi;
        }
    }
    for(int i=18;i>=0;i--)
    {
        if(sp[a][i].fi!=sp[b][i].fi)
        {
            res+=sp[a][i].se+sp[b][i].se;
            a=sp[a][i].fi;
            b=sp[b][i].fi;
        }
    }
    if(a!=b) res+=sp[a][0].se+sp[b][0].se;
    return res;
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dfs(1,1);
    init();
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<query(a,b)<<'\n';
    }
}
