# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
const ll mod=1234567891;
int n;
pair<ll,ll> arr[500010];
bool compare(pair<ll,ll> a,pair<ll,ll> b)
{
    ll resa=(a.second*b.first+b.second);
    ll resb=(a.first*b.second+a.second);
    return resa>resb;
}
int main()
{
    fastio;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr,arr+n,compare);
    ll res=1;
    for(int i=0;i<n;i++) res=(res*arr[i].first+arr[i].second)%mod;
    cout<<res%mod;
}