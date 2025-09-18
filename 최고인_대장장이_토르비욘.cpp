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
pll arr[500010];
int par[500010];
int sz[500010];
ll sum=0;
vector<pll> v2;
vector<ll> v[500010];
set<int> s;
int _find(int x)
{
    if(x==par[x]) return x;
    else return par[x]=_find(par[x]);
}
void _union(int x,int y)
{
    int px=_find(x);
    int py=_find(y);
    if(px>py)
    {
        sz[py]+=sz[px];
        par[px]=py;
    }
    else
    {
        sz[px]+=sz[py];
        par[py]=px;
    }
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
        v2.push_back({arr[i].first,i});
        v2.push_back({arr[i].second,i});
        par[i]=i;
        sz[i]=1;
        sum+=arr[i].first+arr[i].second;
    }
    sort(v2.begin(),v2.end());
    pll recent={-1,-1};
    for(auto i:v2)
    {
        if(recent.first==i.first && _find(recent.second)!=_find(i.second))
        {
            _union(recent.second,i.second);
            //cout<<recent.second<<" "<<i.second<<'\n';
        }
        recent=i;
    }
    //for(int i=1;i<=n;i++) cout<<sz[i]<<'\n';
    for(auto i:v2)
        v[_find(i.second)].push_back(i.first);
    
    for(int i=1;i<=n;i++)
    {
        int x=_find(i);
        if(s.count(x)) continue;
        s.insert(x);
        vector<ll> p;
        for(auto j:v[x]) p.push_back(j);
        sort(p.begin(),p.end());
        p.erase(unique(p.begin(),p.end()),p.end());
        ll sum2=0;
        for(auto j:p) sum2+=j; 
        int node=p.size();
        if(node==sz[x])
            sum-=sum2;
        else
            sum-=(sum2-p[p.size()-1]);       
    }
    cout<<sum;
}