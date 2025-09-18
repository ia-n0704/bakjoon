# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
pair<ll,ll> arr[500010],brr[500010];
vector<pair<ll,ll>> a,b;
ll res=0;
void dnc(ll l,ll r,ll s,ll e)
{
    if(l>r) return;
    ll mid=(l+r)/2;
    ll idx=s,mx=0;
    for(ll i=s;i<=e;i++)
    {
        if(b[i].first<a[mid].first || b[i].second<a[mid].second) continue;
        if((b[i].first-a[mid].first)*(b[i].second-a[mid].second)>=mx)
        {
            mx=(b[i].first-a[mid].first)*(b[i].second-a[mid].second);
            idx=i;
            res=max(res,mx);
        }
    }
    dnc(l,mid-1,s,idx);
    dnc(mid+1,r,idx,e);
}
int main()
{
    fastio;
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>arr[i].first>>arr[i].second;
    for(ll j=1;j<=m;j++)
        cin>>brr[j].first>>brr[j].second;
    sort(arr+1,arr+n+1);
    sort(brr+1,brr+m+1);
    for (ll i=0;i<n;i++)
        if(a.empty() || a.back().second > arr[i+1].second) a.push_back(arr[i+1]);
    for (ll i=0;i<m;i++)
    {
        while(!b.empty() && b.back().second <= brr[i+1].second) b.pop_back();
        b.push_back(brr[i+1]);
    }
    dnc(0,a.size()-1,0,b.size()-1);
    cout<<res;
}