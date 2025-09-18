# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define inf 1e16
ll n,m;
ll st;
ll d[100010];
vector<pair<ll,ll>> v[100010];
void go()
{
    fill(d+1,d+n+1,inf);
    d[st]=0;
    priority_queue<pair<ll,ll>> pq;
    pq.push({0,st});
    while(!pq.empty())
    {
        pair<ll,ll> a=pq.top();
        ll current=a.second;
        ll distance=-a.first;
        pq.pop();
        if(d[current]<distance) continue;
        for(auto j:v[current])
        {
            ll next=j.first;
            ll nextdistance=distance+j.second;
            if(nextdistance<d[next])
            {
                d[next]=nextdistance;
                pq.push({-nextdistance,next});
            }
        }
    }
}
int main()
{
    fastio;
    cin>>n>>m;
    cin>>st;
    for(ll i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    go();
    for(ll i=1;i<=n;i++)
    {
        if(d[i]==inf)
            cout<<"-1\n";
        else
            cout<<d[i]<<'\n';
    }
}