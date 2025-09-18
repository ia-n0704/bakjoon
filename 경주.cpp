# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
const ll inf=1e9;
vector<pair<int,int>> v[200010];
int sz[200010];
int ch[200010];
int n,k;
int res=inf;
int distA[1000010],distB[1000010];
vector<int> ch1,ch2;
int getsize(int x,int y)
{
    sz[x]=1;
    for(auto i:v[x])
    {
        if(i.first!=y && !ch[i.first]) 
            sz[x]+=getsize(i.first,x);
    }
    return sz[x];
}
int getcent(int x,int y,int S)
{
    for(auto i:v[x])
    {
        if(i.first!=y && sz[i.first]*2>S && !ch[i.first])
            return getcent(i.first,x,S);
    }
    return x;
}
void dfs(int x,int y,int dist,int cnt)
{
    if(dist==k)
    {
        res=min(res,cnt);
        return;
    }
    if(dist>k) return;
    if(distA[k-dist]!=inf) res=min(res,cnt+distA[k-dist]);
    distB[dist]=min(distB[dist],cnt);
    ch1.push_back(dist);
    ch2.push_back(dist);
    for(auto i:v[x])
    {
        if(i.first!=y && !ch[i.first]) 
            dfs(i.first,x,dist+i.second,cnt+1);
    }
}
void dnc(int x)
{
    int cent=getcent(x,-1,getsize(x,-1));
    for(auto i:v[cent])
    {
        if(!ch[i.first])
        {
            dfs(i.first,cent,i.second,1);
            for(auto j:ch1)
                distA[j]=min(distA[j],distB[j]);
            ch1.clear();
        }
    }
    for(auto i:ch2)
    {
        distA[i]=inf;
        distB[i]=inf;
    }
    ch2.clear();
    ch[cent]=1;
    for(auto i:v[cent])
        if(!ch[i.first]) dnc(i.first);
}
int main()
{
    fastio;
    cin>>n>>k;
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    fill(distA,distA+k+1,inf);
    fill(distB,distB+k+1,inf);
    dnc(0);
    if(res==inf) cout<<-1;
    else
        cout<<res;
}