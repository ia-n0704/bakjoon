# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,d;
pll arr[100010];
ll sum[100010];
bool compare(pll a,pll b)
{
    if(a.first==b.first) return a.second>b.second;
    return a.first<b.first;
}
int main()
{
    fastio;
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr+1,arr+n+1,compare);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+arr[i].second;
    int l=1,r=1;
    ll res=0;
    for(;l<=n;l++)
    {
        while(r<n && arr[r+1].first-arr[l].first<d) r++;
        res=max(res,sum[r]-sum[l-1]);
    }
    cout<<res;
}