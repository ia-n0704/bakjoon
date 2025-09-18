# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define inf 1e9
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m;
vector<pair<int,int>> v[1010];
int d[1010];
int st,en;
void go()
{
    fill(d+1,d+1+n,inf);
    d[st]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,st});
    while(!pq.empty())
    {
        auto a=pq.top();
        pq.pop();
        if(d[a.second]<-a.first) continue;
        for(auto j:v[a.second])
        {
            //cout<<a.first<<'\n';
            if(-a.first+j.second<d[j.first])
            {
                d[j.first]=-a.first+j.second;
                pq.push({a.first-j.second,j.first});
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
    cout<<d[en];
}