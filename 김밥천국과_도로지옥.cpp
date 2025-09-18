#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll,ll> pll;
const ll inf=1e16;
int n,m;
ll k;
ll d[100010][15];
struct T
{
    ll dist,node,mod;
    bool operator < (const T &b) const
    {
        return dist>b.dist;
    }
};
vector<pll> v[100010];
void go()
{
    for(int i=0;i<=n;i++)
        fill(d[i],d[i]+12,inf);
    d[1][0]=0;
    priority_queue<T> pq;
    pq.push({0,1,0});
    while(!pq.empty())
    {
        auto a=pq.top();
        ll current=a.node;
        ll distance=a.dist;
        ll mod=a.mod; 
        pq.pop();
        if(d[current][mod]<distance) continue;
        for(auto j:v[current])
        {
            ll next=j.first;
            ll nextdistance=distance+j.second;
            ll nextmod=(mod+j.second)%12;
            if(nextdistance<d[next][nextmod])
            {
                d[next][nextmod]=nextdistance;
                pq.push({nextdistance,next,nextmod});
            }
        }
    }
}
int main()
{
    fastio;
    cin>>n>>m;
    cin>>k;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    go();
    //cout<<d[n][k%12];
    if(d[n][k%12]<=k) cout<<"YES";
    else cout<<"NO";
}