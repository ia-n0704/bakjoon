# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m,st,en,k;
const ll inf=1e16;
struct T
{
    int x,y;
    ll co;
};
vector<ll> arr[2010];
vector<pll> v[2010];
ll dist[2010][110];
int main()
{
    fastio;
    cin>>n>>m>>st>>en;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        arr[i].push_back(c);
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        int a;
        for(int j=1;j<=m;j++)
        {
            cin>>a;
            arr[j].push_back(a);
        }
    }
    for(int i=0;i<=n;i++)
        fill(dist[i],dist[i]+k+1,inf);
    priority_queue<pair<ll,pair<int,int>>> pq;
    pq.push({0,{st,0}});
    while(!pq.empty())
    {
        auto a=pq.top();
        a.first*=-1;
        //cout<<a.first<<" "<<a.second.first<<" "<<a.second.second<<'\n';
        pq.pop();
        if(dist[a.second.first][a.second.second]<a.first) continue;
        for(auto i:v[a.second.first])
        {
            for(int j=a.second.second;j<=k;j++)
            {
                //cout<<"| "<<i.first<<" "<<j<<" "<<v[i.first][j].second<<'\n';
                if(dist[i.first][j]>a.first+arr[i.second][j])
                {
                    dist[i.first][j]=a.first+arr[i.second][j];
                    pq.push({-dist[i.first][j],{i.first,j}});
                }
            }
        }
    }
    ll res=inf;
    for(int i=0;i<=k;i++)
        res=min(res,dist[en][i]);
    cout<<res;
}