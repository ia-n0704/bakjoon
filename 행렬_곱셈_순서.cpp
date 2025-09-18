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
ll arr[1000];
ll dp[1000][1000];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>arr[i]>>a;
        arr[n+1]=a;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            int st=j,en=j+i-1;
            dp[st][en]=arr[st]*arr[st+1]*arr[en+1]+dp[st][st]+dp[st+1][en];
            for(int k=st+1;k<en;k++)
            {
                dp[st][en]=min(dp[st][en],dp[st][k]+dp[k+1][en]+arr[st]*arr[k+1]*arr[en+1]);
            }
        }
    }
    cout<<dp[1][n];
}