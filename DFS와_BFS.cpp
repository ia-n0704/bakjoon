# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m,st;
vector<int> v[1010];
int ch1[1010],ch2[1010];
void dfs(int x)
{
    cout<<x<<" ";
    ch1[x]=1;
    for(auto i:v[x]) if(ch1[i]==0) dfs(i);
}
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        if(ch2[a]) continue;
        cout<<a<<" ";
        ch2[a]=1;
        for(auto i:v[a])
            if(ch2[i]==0) q.push(i);
    }
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
        sort(v[i].begin(),v[i].end());
    dfs(st);
    cout<<'\n';
    bfs(st);
}