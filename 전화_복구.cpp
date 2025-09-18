# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,m;
pair<ll,ll> arr[100010];
int main()
{
    fastio;
    cin>>n>>m;
    ll res=0;
    for(int i=1;i<=n;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr+1,arr+n+1);
    ll num=1e16;
    for(int i=1;i<=n;i++)
    {
        if(num==1e16) res+=arr[i].second;
        if(arr[i].second>num)res+=ll(arr[i].second-num);
        num=arr[i].second;
    }
    cout<<res;
}