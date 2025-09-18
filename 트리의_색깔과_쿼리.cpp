#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define all(v) (v).begin(),(v).end()
int n,q;
int par[200010];
int p[200010];
int c[200010];
set<int> s[200010];
vector<pii> query;
int _find(int x)
{
    if(par[x]==x) return x;
    return par[x]=_find(par[x]);
}
void merge(int x,int y)
{
    int fx=_find(x),fy=_find(y);
    if(fx==fy) return;
    if(s[fx].size()>s[fy].size()) swap(fx,fy);
    par[fx]=fy;
    for(auto i:s[fx]) s[fy].insert(i);
    return;
}
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>q;
    for(int i=2;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=n;i++)
    {
        par[i]=i;
        cin>>c[i];
        s[i].insert(c[i]);
    }
    for(int i=1;i<n+q;i++)
    {
        int a,b;
        cin>>a>>b;
        query.push_back({a,b});
    }
    reverse(all(query));
    vector<int> ans;
    for(int i=0;i<query.size();i++)
    {
        int x=query[i].first;
        int y=query[i].second;
        if(x==2) ans.push_back(s[_find(y)].size());
        else merge(y,p[y]);
    }
    reverse(all(ans));
    for(auto i:ans) cout<<i<<'\n';
}