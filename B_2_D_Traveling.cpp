# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int n,k,a,b;
pll arr[200010];
ll dist(pll x,pll y)
{
    return abs(x.first-y.first)+abs(x.second-y.second);
}
void sol()
{
    cin>>n>>k>>a>>b;
    for(int i=1;i<=n;i++)
        cin>>arr[i].first>>arr[i].second;
    ll res=dist(arr[a],arr[b]);
    ll stmin=(ll)1e16,enmin=(ll)1e16;
    for(int i=1;i<=k;i++)
    {
        stmin=min(stmin,dist(arr[i],arr[a]));
        enmin=min(enmin,dist(arr[i],arr[b]));
    }
    res=min(res,stmin+enmin);
    cout<<res<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}