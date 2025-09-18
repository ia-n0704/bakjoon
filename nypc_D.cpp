#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
vector<int> v[200010];
int d[200010];
int n,m;
string res;
vector<pair<string,int>> ans;
bool compare(pair<string,int> a,pair<string,int> b)
{
    if(a.first.length()<b.first.length()) return 1;
    else if(a.first.length()>b.first.length()) return 0;
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
void dfs(int x,string s,int dest,int par)
{
    if(x==dest)
    {
        res=s;
        return;
    }
    for(auto i:v[x])
    {
        if(i!=par)
            dfs(i,s+char(d[i]+'0'),dest,x);
    }
}
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>d[i];
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        res="";
        string st;
        st+=(char)(d[a]+'0');
        dfs(a,st,b,0);
        ans.push_back({res,i});
        //cout<<res<<'\n';
    }
    sort(ans.begin(),ans.end(),compare);
    for(int i=0;i<ans.size();i++) cout<<ans[i].second<<'\n';
}