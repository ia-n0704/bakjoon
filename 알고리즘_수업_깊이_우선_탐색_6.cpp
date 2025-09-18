# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
vector<int> v[100010];
int dep[100010];
int num[100010];
int ch[100010];
int cnt;
int n,m,st;
void dfs(int x,int d)
{
    dep[x]=d;
    num[x]=++cnt;
    ch[x]=1;
    for(auto i:v[x])
        if(!ch[i]) dfs(i,d+1);
}
int main()
{
    fastio;
    cin>>n>>m>>st;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        sort(v[i].begin(),v[i].end());
        reverse(v[i].begin(),v[i].end());
    }
    dfs(st,0);
    ll res=0;
    for(int i=1;i<=n;i++)
        res+=(ll)num[i]*(ll)dep[i];
    cout<<res;
}