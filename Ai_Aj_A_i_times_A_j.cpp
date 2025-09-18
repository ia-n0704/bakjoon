# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
ll arr[200010];
ll sum;
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr+1,arr+n+1);
    ll res=sum;
    ll num=arr[n]*arr[n-1];
    num=sum+num*2-arr[n]-arr[n-1];
    res=max(res,num);
    num=arr[1]*arr[2];
    num=sum+num*2-arr[1]-arr[2];
    res=max(res,num);
    cout<<res;
}