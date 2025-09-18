# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
vector<pair<int,int>> v[1000010];
int n;
int ch_node[1000010];
int ch_road[1000010];
int dfs(int x,int p,int last)
{
    ch_node[x]=1;
    for(auto i:v[x])
    {
        if(ch_road[i.second] || last==i.second) continue;
        if(ch_node[i.first])
        {
            ch_road[i.second]=x;
            return p;
        }
        else
        {
            ch_road[i.second]=dfs(i.first,x,i.second);
            if(ch_road[i.second]==x)
                return p;
        }
    }
    return x;
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }
    for(int i=1;i<=1000000;i++)
    {
        if(ch_node[i]==0)
            dfs(i,0,0);
    }
    vector<int> ans;
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        if(ch_road[i]==0)
        {
            cout<<-1;
            return 0;
        }
        ans.push_back(ch_road[i]);
    }
    for(auto i:ans) cout<<i<<'\n';
}