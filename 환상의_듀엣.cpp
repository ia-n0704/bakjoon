# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define inf 1e16
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n;
ll arr[2024];
ll dp[2024][2024];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++) dp[i][j]=inf;
    dp[0][0]=dp[0][1]=dp[1][0]=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i!=j)
            {
                int idx=max(i,j)+1;
                arr[0]=arr[idx];
                dp[idx][j]=min(dp[idx][j],dp[i][j]+abs(arr[idx]-arr[i]));
                dp[i][idx]=min(dp[i][idx],dp[i][j]+abs(arr[idx]-arr[j]));
            }
        }
    }
    ll res=inf;
    for(int i=0;i<=n;i++)
        res=min(res,min(dp[i][n],dp[n][i]));
    cout<<res;
}