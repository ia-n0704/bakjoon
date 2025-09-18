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
vector<int> v[100010];
ll rb[100010];
int par[100010];
ll sz[100010];
ll res=0;
int _find(int x)
{
    if(x==par[x]) return x;
    return par[x]=_find(par[x]);
}
void _union(int x,int y)
{
    int fx=_find(x);
    int fy=_find(y);
    if(fx==fy) return;
    if(fx>fy) swap(fx,fy);
    par[fy]=fx;
    sz[fx]+=sz[fy];
}
int main()
{
    fastio;
    cin>>n;
    fill(sz,sz+n+1,1);
    for(int i=1;i<=n;i++) par[i]=i;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='R') rb[i+1]=0;
        else rb[i+1]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(rb[i]) continue;
        for(auto j:v[i])
            if(rb[j]==0) _union(i,j);
    }
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        if(rb[i])
        {
            for(auto j:v[i])
            {
                if(rb[j]==0) res+=sz[_find(j)];
                //cout<<i<<" "<<j<<" | "<<res<<'\n';
            }
        }
    }
    cout<<res;
}
