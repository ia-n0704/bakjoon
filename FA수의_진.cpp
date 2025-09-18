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
int arr[100010],brr[100010],crr[100010],drr[100010];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i]>>brr[i]>>crr[i]>>drr[i];
    ll t=0;
    for(int i=1;i<=n;i++)
    {
        int num=0;
        if(t%(crr[i]+drr[i])>=crr[i]) num=(crr[i]+drr[i])-t%(crr[i]+drr[i]);
        t+=min(brr[i],arr[i]+num);
    }
    cout<<t;
}