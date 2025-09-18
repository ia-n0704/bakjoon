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
int arr[101][101];
int dp[101][101];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin>>arr[i][j];
    int res=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=1;
            for(int x=1;x<=i;x++)
            {
                for(int y=1;y<=j;y++)
                {
                    if(arr[i][j]>arr[x][y])
                        dp[i][j]=max(dp[i][j],dp[x][y]+1);
                }
            }
            res=max(res,dp[i][j]);
        }
    }
    cout<<res;
}