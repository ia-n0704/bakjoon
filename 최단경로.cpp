#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define inf 1e9
int n,m;
int st;
int d[20010];
vector<pair<int,int>> v[20010];
void go()
{
    fill(d+1,d+n+1,inf);
    d[st]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,st});
    while(!pq.empty())
    {
        pair<int,int> a=pq.top();
        int current=a.second;
        int distance=-a.first;
        pq.pop();
        if(d[current]<distance) continue;
        for(auto j:v[current])
        {
            int next=j.first;
            int nextdistance=distance+j.second;
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
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    go();
    for(int i=1;i<=n;i++)
    {
        if(d[i]==inf)
            cout<<"INF\n";
        else
            cout<<d[i]<<'\n';
    }
}