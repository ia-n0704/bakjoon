# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
vector<int> v[200010];
int a,b,x;
int cnt;
int ch[200010];
int vis[200010];
void dfs(int t,int flag)
{
    vis[t]=1;
    if(t==x) flag=1;
    if(flag) ch[t]=1;
    for(auto i:v[t])
        if(vis[i]==0) dfs(i,flag);
}
void dfs2(int t,int flag)
{
    vis[t]=1;
    if(t==x) flag=1;
    if(flag && ch[t]) cnt++;
    for(auto i:v[t])
        if(vis[i]==0) dfs2(i,flag);
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int p,q;
        cin>>p>>q;
        v[p].push_back(q);
        v[q].push_back(p);
    }
    cin>>a>>b>>x;
    dfs(a,0);
    fill(vis,vis+n+1,0);
    dfs2(b,0);
    cout<<cnt;
}