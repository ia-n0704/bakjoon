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
int n,m;
vector<int> v[200010],v2[200010];
vector<pair<int,pii>> res;
int ch[200010],ch2[200010];
int num[200010];
int node_cnt;
set<pii> s;
void dfs(int x)
{
    ch[x]=1;
    for(auto i:v[x])
    {
        if(s.count({x,i})) continue;
        s.insert({x,i});
        s.insert({i,x});
        if(ch[i])
        {
            node_cnt++;
            num[node_cnt]=i;
            v2[x].push_back(node_cnt);
        }
        else
        {
            v2[x].push_back(i);
            dfs(i);
        }
    }
}
void sol(int x,int par)
{
    for(auto i:v2[x]) sol(i,x);
    vector<int> temp;
    for(auto i:v2[x])
        if(ch2[i]==0) temp.push_back(i);
    for(int i=0;i<int(temp.size())-1;i+=2)
        res.push_back({num[x],{num[temp[i]],num[temp[i+1]]}});
    if(temp.size()%2 && par!=0)
    {
        ch2[x]=1;
        res.push_back({num[x],{num[temp[temp.size()-1]],num[par]}});
    }
}
int main()
{
    fastio;
    cin>>n>>m;
    node_cnt=n;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++) num[i]=i;
    for(int i=1;i<=n;i++)
    {
        if(ch[i]==0)
        {
            dfs(i);
            sol(i,0);
        }
    }
    cout<<res.size()<<'\n';
    for(auto i:res)
        cout<<i.second.first<<" "<<i.first<<" "<<i.second.second<<'\n';
}
