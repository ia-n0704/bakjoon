# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n;
struct line
{
    pair<ll,ll> mid,p1,p2;
    ll dist;
}arr[1510*1510];
bool compare(line a,line b)
{
    if(a.mid.first==b.mid.first)
    {
        if(a.mid.second==b.mid.second)
            return a.dist<b.dist;
        return a.mid.second<b.mid.second;
    }        
    return a.mid.first<b.mid.first;
}
ll dist(pair<ll,ll> a,pair<ll,ll> b)
{
    return (ll)(a.first-b.first)*(a.first-b.first)+(ll)(a.second-b.second)*(a.second-b.second);
}
ll ccw(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c)
{
    return abs((a.first*b.second+b.first*c.second+c.first*a.second)-(b.first*a.second+c.first*b.second+a.first*c.second));
}
pair<ll,ll> p[2000];
int main()
{
    fastio;
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>p[i].first>>p[i].second;
    vector<line> v;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i+1;j<=n;j++)
        {
            pair<ll,ll> a=p[i],b=p[j];
            pair<ll,ll> mid={p[i].first+p[j].first,p[i].second+p[j].second};
            ll d=dist(a,b);
            v.push_back({mid,a,b,d});
        }
    }
    sort(v.begin(),v.end(),compare);
    ll num=0;
    for(ll i=0;i<v.size();i++)
    {
        for(ll j=i+1;j<v.size();j++)
        {
            if(v[i].mid!=v[j].mid || v[i].dist!=v[j].dist) break;
            num=max(num,ccw(v[i].p1,v[j].p1,v[i].p2));
        }
    }
    cout<<num;
}