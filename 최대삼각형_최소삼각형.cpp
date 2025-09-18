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
pll arr[2010];
ll idx[2010];
vector<pair<pll,pll>> line;
ll ccw(pll a,pll b,pll c)
{
    return abs((a.first*b.second+b.first*c.second+c.first*a.second)-(a.second*b.first+b.second*c.first+c.second*a.first));
}
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
int main()
{
    fastio;
    while(1)
    {
        cin>>n;
        if(!n) break;
        for(ll i=1;i<=n;i++)
            cin>>arr[i].first>>arr[i].second;
        sort(arr+1,arr+n+1);
        iota(idx+1,idx+n+1,1);
        line.clear();
        for(ll i=1;i<=n;i++)
            for(ll j=i+1;j<=n;j++)
                line.push_back({{i,j},{arr[i].first-arr[j].first,arr[i].second-arr[j].second}});
        sort(line.begin(),line.end(),compare);
        ll mn=1e16;
        ll mx=0;
        ll j=0;
        //cout<<cmp(line[0].second,line[0].second)<<'\n';
        for(ll i=0;i<line.size();i=j)
        {
            while(j<line.size() && cmp(line[i],line[j])) j++;
            for(ll k=i;k<j;k++)
            {
                ll l=line[k].first.first;
                ll r=line[k].first.second;
                swap(idx[l],idx[r]);
                swap(arr[idx[l]],arr[idx[r]]);
                if(idx[l]>idx[r]) swap(l,r);
                if(idx[l]>1)
                {
                    mn=min(mn,ccw(arr[idx[l]],arr[idx[r]],arr[idx[l]-1]));
                    mx=max(mx,ccw(arr[idx[l]],arr[idx[r]],arr[1]));
                }
                if(idx[r]<n)
                {
                    mn=min(mn,ccw(arr[idx[l]],arr[idx[r]],arr[idx[r]+1]));
                    mx=max(mx,ccw(arr[idx[l]],arr[idx[r]],arr[n]));
                }
            }
        }
        cout<<mn/2;
        if(mn%2) cout<<".5";
        else cout<<".0";
        cout<<" "<<mx/2;
        if(mx%2) cout<<".5";
        else cout<<".0";
        cout<<'\n';
    }
}