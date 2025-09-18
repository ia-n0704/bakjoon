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
int arr[2024];
int dp[2024];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    int res=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=1;
        for(int j=1;j<i;j++)
            if(arr[i]<arr[j])
                dp[i]=max(dp[i],dp[j]+1);
        res=max(res,dp[i]);
    }
    cout<<res;
}