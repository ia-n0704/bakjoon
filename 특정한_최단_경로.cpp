# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll inf=1e16;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll d[1010][1010];
int ch[1010];
vector<pair<ll,ll>> v[1010];
int n,m;
void go(int a)
{
    fill(ch,ch+n+1,0);
    fill(d[a],d[a]+n+1,inf);
    d[a][a]=0;
    priority_queue<pair<ll,ll>> pq;
    pq.push({0,a});
    while(!pq.empty())
    {
        auto t=pq.top();
        pq.pop();
        int cur=t.second;
        int dis=-t.first;
        ch[cur]=1;
        for(auto i:v[cur])
        {
            if(ch[i.first]) continue;
            //cout<<v[1][0].first<<'\n';
            if(d[a][i.first]>dis+i.second)
            {
                d[a][i.first]=dis+i.second;
                pq.push({-(dis+i.second),i.first});
            }
        }
    }
}
int main()
{
    fastio;
    cin>>n>>m;
    int p,q;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    cin>>p>>q;
    go(1);
    go(p);
    go(q);
    ll mx=0;
    ll res=min(d[1][p]+d[p][q]+d[q][n],d[1][q]+d[q][p]+d[p][n]);
    if(res>=inf)
        cout<<-1;
    else cout<<res;
}