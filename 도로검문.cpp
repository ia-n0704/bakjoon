#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define inf 1e9
int n,m;
int st;
int d[20010];
int par[20010];
vector<pair<int,int>> v[20010];
int flag;
void go(int x,int y)
{
    fill(d+1,d+n+1,inf);
    d[1]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,1});
    while(!pq.empty())
    {
        pair<int,int> a=pq.top();
        int current=a.second;
        int distance=-a.first;
        pq.pop();
        if(d[current]<distance) continue;
        for(auto j:v[current])
        {
            if((current==x && j.first==y) || (current==y && j.first==x))
                continue;
            int next=j.first;
            int nextdistance=distance+j.second;
            if(nextdistance<d[next])
            {
                if(!flag) par[next]=current;
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
    vector<pair<int,int>> arr;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        arr.push_back({a,b});
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    go(0,0);
    flag=1;
    int num=d[n];
    int mx=0;
    par[1]=1;
    //for(int i=1;i<=n;i++) cout<<i<<" "<<par[i]<<'\n';
    for(int i=n;i!=par[i];i=par[i])
    {
        go(par[i],i);
        if(d[n]==inf)
        {
            cout<<-1;
            return 0;
        }
        mx=max(mx,d[n]-num);
    }
    cout<<mx;
}