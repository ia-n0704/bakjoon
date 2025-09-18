# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,m;
ll st,en;
const ll inf=1e16;
pair<ll,ll> d[1010];
vector<pair<ll,ll>> v[1010];
void go()
{
    for(int i=0;i<=n;i++)
        d[i].second=inf;
    d[st]={-1,0};
    priority_queue<pair<int,int>> pq;
    pq.push({0,st});
    while(!pq.empty())
    {
        auto a=pq.top();
        pq.pop();
        ll cur=a.second;
        ll dis=-a.first;
        if(dis>d[cur].second) continue;
        //cout<<cur<<" "<<dis<<'\n';
        for(auto i:v[cur])
        {
            if(d[i.first].second>dis+i.second)
            {
                d[i.first].first=cur;
                d[i.first].second=dis+i.second;
                pq.push({-d[i.first].second,i.first});
            }
        }
    }
}
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    cin>>st>>en;
    go();
    vector<int> ans;
    ll temp=en;
    while(temp!=-1)
    {
        ans.push_back(temp);
        temp=d[temp].first;
    }
    cout<<d[en].second<<'\n';
    cout<<ans.size()<<'\n';
    for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
}