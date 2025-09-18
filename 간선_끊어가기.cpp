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
vector<pii> v[5010];
int s,t;
int dist[5010][2];
int main()
{
    fastio;
    cin>>n>>m;
    int sum=0;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        sum+=c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    cin>>s>>t;
    priority_queue<pair<pii,int>,vector<pair<pii,int>>,greater<pair<pii,int>>> pq;
    pq.push({{0,s},1});
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=1;j++)
            dist[i][j]=1e9;
    }
    dist[s][1]=0;
    while(!pq.empty())
    {
        auto a=pq.top();
        pq.pop();
        int cur=a.fi.se;
        int co=a.fi.fi;
        int flag=a.se;
        //cout<<cur<<" "<<co<<" "<<flag<<'\n';
        if(co>dist[cur][flag]) continue;
        for(auto a:v[cur])
        {
            int nx=a.fi;
            int nx_co=a.se;
            if(dist[nx][flag]>co+nx_co)
            {
                dist[nx][flag]=co+nx_co;
                pq.push({{dist[nx][flag],nx},flag});
            }
            if(flag && dist[nx][0]>co)
            {
                dist[nx][0]=co;
                pq.push({{dist[nx][0],nx},0});
            }
        }
    }
    cout<<sum-dist[t][0];
}
