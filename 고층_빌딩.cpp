# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define mod 1000000007
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll dp[101][101][101];
int main()
{
    fastio;
    int n;
    int l,r;
    cin>>n>>l>>r;
    dp[1][1][1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            for(int k=1;k<=i;k++)
            {
                dp[i][j][k]=dp[i-1][j-1][k]+dp[i-1][j][k-1]+dp[i-1][j][k]*(i-2);
                dp[i][j][k]%=mod;
            }
        }
    }
    cout<<dp[n][l][r];
}