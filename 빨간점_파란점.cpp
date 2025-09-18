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
pair<pll,ll> arr[2010];
ll idx[2010];
vector<pair<pll,pll>> line;
struct Seg
{
    ll mx,l,r,sum;
}tree[10010];
bool cmp(pair<pll,pll> x,pair<pll,pll> y)
{
    return x.second.first*y.second.second==x.second.second*y.second.first;
}
bool compare(pair<pll,pll> x,pair<pll,pll> y)
{
    if(cmp(x,y)) 
    {
        if(x.first.first==y.first.first)
            return x.first.second<y.first.second;
        return x.first.first<y.first.first;
    }
    return x.second.first*y.second.second>x.second.second*y.second.first;
}
Seg merge(Seg a,Seg b)
{
    Seg c;
    if(a.sum==a.l)
        c.l=a.l+b.l;
    else c.l=a.l;
    if(b.sum==b.r)
        c.r=b.r+a.r;
    else c.r=b.r;
    c.sum=a.sum+b.sum;
    c.mx=max(a.r+b.l,max(a.mx,b.mx));
    return c;
}
void update(ll v,ll l,ll r,ll idx,ll num)
{
    if(idx<l || idx>r) return;
    if(l==r)
    {
        tree[v]={num,num,num,1};
        return;
    }
    ll mid=(l+r)/2;
    update(v*2,l,mid,idx,num);
    update(v*2+1,mid+1,r,idx,num);
    tree[v]=merge(tree[v*2],tree[v*2+1]);
}
Seg query(ll v,ll l,ll r,ll s,ll e)
{
    if(l>e || r<s) return {0,0,0,1};
    if(l>=s && r<=e)
        return tree[v];
    ll mid=(l+r)/2;
    return merge(query(v*2,l,mid,s,e),query(v*2+1,mid+1,r,s,e));
}
int main()
{
    fastio;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        char c;
        cin>>arr[i].first.first>>arr[i].first.second>>c;
        if(c=='R') arr[i].second=1;
        else arr[i].second=0;
    }
    sort(arr+1,arr+n+1);
    iota(idx+1,idx+n+1,1);
    for(ll i=1;i<=n;i++)
        update(1,1,n,i,arr[i].second);
    for(ll i=1;i<=n;i++)
        for(ll j=i+1;j<=n;j++)
            line.push_back({{i,j},{arr[i].first.first-arr[j].first.first,arr[i].first.second-arr[j].first.second}});
    sort(line.begin(),line.end(),compare);
    ll mx=max(0ll,query(1,1,n,1,n).mx);
    ll j=0;
    for(ll i=0;i<line.size();i=j)
    {
        while(j<line.size() && cmp(line[i],line[j])) j++;
        for(ll k=i;k<j;k++)
        {
            ll l=line[k].first.first;
            ll r=line[k].first.second;
            swap(idx[l],idx[r]);
            swap(arr[idx[l]],arr[idx[r]]);
            update(1,1,n,idx[l],arr[idx[l]].second);
            update(1,1,n,idx[r],arr[idx[r]].second);
        }
        if(j==line.size() || cmp(line[j],line[j-1])==0)
            mx=max(mx,query(1,1,n,1,n).mx);
    }
    cout<<mx;
}