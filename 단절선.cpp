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
pair<int,int> arr[200010];
vector<pair<int,int>> ans;
int n,m;
int ch[100010];
int cut[100010];
int cnt;
int dfs(int x,int root)
{
    ch[x]=++cnt;
    int res=ch[x];
    for(auto i:v[x])
    {
        if(i==root) continue;
        if(ch[i])
        {
            res=min(res,ch[i]);
            continue;
        }
        int temp=dfs(i,x);
        res=min(res,temp);
        if(temp>ch[x])
            ans.push_back({x,i});
    }
    return res;
}
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        arr[i]={a,b};
    }
    for(int i=1;i<=n;i++)
        if(ch[i]==0) dfs(i,0);
    set<pair<int,int>> s;
    for(auto i:ans)
        s.insert(i);
    for(int i=1;i<=m;i++)
    {
        if(s.count({arr[i].first,arr[i].second}) || s.count({arr[i].second,arr[i].first})) cout<<1;
        else cout<<0;
    }
 }