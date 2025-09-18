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
pair<int,int> arr[1500010];
int dp[1500010];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i].first>>arr[i].second;
    for(int i=1;i<=n+1;i++)
    {
        dp[i]=max(dp[i-1],dp[i]);
        if(i+arr[i].first<=n+1)
            dp[i+arr[i].first]=max(dp[i+arr[i].first],dp[i]+arr[i].second);
    }
    cout<<dp[n+1];
}