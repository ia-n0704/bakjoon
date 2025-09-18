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
pair<ll,ll> arr[2010];
pll temp;
ll ccw(pll a,pll b,pll c)
{
    return (a.first*b.second+b.first*c.second+c.first*a.second)-(a.second*b.first+b.second*c.first+c.second*a.first);
}
bool compare(pll x, pll y)
{
    pll X={x.first-temp.first,x.second-temp.second};
    pll Y={y.first-temp.first,y.second-temp.second};
    if((X.first<0)!=(Y.first<0))
        return X.first<Y.first;
    if(X.first==0 && Y.first==0)
        return X.second<Y.second;
    return X.second*Y.first<X.first*Y.second;
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i].first>>arr[i].second;
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        temp=arr[i];
        vector<pair<ll,ll>> v;
        for(int j=1;j<=n;j++)
            if(i!=j) v.push_back(arr[j]);
        sort(v.begin(),v.end(),compare);
        ll idx1=0,idx2=0;
        for(auto a:v)
        {
            while(ccw(arr[i],a,v[idx1%(n-1)])>=0 && idx2<n-1)
            {
                idx1++;
                idx2++;
            }
            res+=(idx2-1)*(idx2-2)/2;
            idx2--;
        }
    }
    ll num=n*(n-1)*(n-2)*(n-3)/24;
    num=(res-num*2)*10000;
    printf("%.5f",(num/(n*(n-1)*(n-2)/6))/10000.0+3);
}