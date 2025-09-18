# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m,k;
pair<int,int> arr[500010];
int cost[500010];
int rest[500010];

vector<int> graph[500010];
stack<int> s;
int ch[500010];

vector<int> rev_graph[500010];
int ch2[500010];

int group[500010];
vector<int> SCC[500010];
vector<int> new_graph[500010];
int big_cost[500010];

int st;

int dp[500010];
int indeg[500010];

void dfs(int v)
{
    ch[v]=1;
    for(auto i:graph[v])
    {
        if(ch[i]==0)
            dfs(i);
    }
    s.push(v);
}
int scc_cnt;
void dfs2(int v)
{
    ch2[v]=1;
    group[v]=scc_cnt;
    SCC[scc_cnt].push_back(v);
    for(auto i:rev_graph[v])
    {
        if(ch2[i]==0)
            dfs2(i);
    }
}
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        rev_graph[b].push_back(a);
        arr[i]={a,b};
    }
    for(int i=1;i<=n;i++)
        if(ch[i]==0) dfs(i);
    while(!s.empty())
    {
        if(ch2[s.top()]==0)
        {
            scc_cnt++;
            dfs2(s.top());
        }
        s.pop();
    }
    for(int i=1;i<=m;i++)
    {
        int a=arr[i].first,b=arr[i].second;
        if(group[a]==group[b]) continue;
        new_graph[group[a]].push_back(group[b]);
        indeg[group[b]]++;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>cost[i];
        big_cost[group[i]]+=cost[i];
    }
    cin>>st>>k;
    for(int i=1;i<=k;i++)
        cin>>rest[i];
    queue<int> q;
    for(int i=1;i<=scc_cnt;i++)
        if(indeg[i]==0) q.push(i);
    int flag=0;
    dp[group[st]]=big_cost[group[st]];
    while(!q.empty())
    {
        int v=q.front();
        if(v==group[st]) flag=1;
        q.pop();
        for(auto i:new_graph[v])
        {
            indeg[i]--;
            if(flag) dp[i]=max(dp[i],dp[v]+big_cost[i]);
            if(indeg[i]==0)
                q.push(i);
        }
    }
    int res=0;
    for(int i=1;i<=k;i++)
        res=max(res,dp[group[rest[i]]]);
    cout<<res;
}