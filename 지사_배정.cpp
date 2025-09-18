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
ll n,b,s,r;
vector<pair<ll,ll>> v1[5010],v2[5010];
vector<ll> dis1,dis2;
ll resdis[5010];
ll sum[5010];
ll dp[5010][5010];
void go(int st,vector<pair<ll,ll>> v[5010],vector<ll> &dis)
{
    dis[st]=0;
    priority_queue <pair<ll,ll>> pq;
    pq.push({0,st});
    while(!pq.empty())
    {
        auto a=pq.top();
        pq.pop();
        ll cur=a.second;
        ll num=-a.first;
        if(num>dis[cur]) continue;
        for(auto i:v[cur])
        {
            if(dis[i.first]>num+i.second)
            {
                dis[i.first]=num+i.second;
                pq.push({-dis[i.first],i.first});
            }
        }
    }
}
void dnc(int idx,int s,int e,int l,int r)
{
    if(s>e) return;
    int mid=(s+e)/2;
    dp[idx][mid]=dp[idx-1][l]+(mid-l-1)*(sum[mid]-sum[l]);
    ll temp=l;
    for(int i=l;i<min(mid,r);i++)
    {
        ll num=dp[idx-1][i]+(mid-i-1)*(sum[mid]-sum[i]);
        if(dp[idx][mid]>num)
        {
            dp[idx][mid]=num;
            temp=i;
        }
    }
    dnc(idx,s,mid-1,l,temp+1);
    dnc(idx,mid+1,e,temp,r);
}
int main()
{
    fastio;
    cin>>n>>b>>s>>r;
    for(int i=0;i<r;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        v1[a].push_back({b,c});
        v2[b].push_back({a,c});
    }
    dis1.resize(n+1);
    dis2.resize(n+1);
    fill(dis1.begin(),dis1.end(),inf);
    fill(dis2.begin(),dis2.end(),inf);
    go(b+1,v1,dis1);
    go(b+1,v2,dis2);
    for(int i=1;i<=b;i++)
        resdis[i]=dis1[i]+dis2[i];
    sort(resdis+1,resdis+b+1);
    for(int i=1;i<=b;i++)
        sum[i]=sum[i-1]+resdis[i];
    for(int i=1;i<=b;i++)
        dp[1][i]=(i-1)*sum[i];
    for(int i=2;i<=s;i++)
        dnc(i,i,b,i-1,b);
    cout<<dp[s][b];
}