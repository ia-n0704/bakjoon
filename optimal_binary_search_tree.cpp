# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
ll f[5010][5010];
ll arr[5010];
int n;
ll dp[5010][5010];
void opt(int x,int y)
{
    dp[x][y]=1e18;
    for(int i=x;i<=y;i++)
        if(dp[x][y]>dp[x][i-1]+dp[i+1,y])
            dp[x][y]=dp[x][i-1]+dp[i+1,y]
    dp[x][y]+=f[x][y];
}
void sol()
{
    for(int i=1;i<=n+1;i++)
        dp[i][i-1]=0;
    for(int i=0;i<n;i++)
        for(int j=1;j<=n-d;j++)
            opt(j,j+i);
    cout<<dp[1][n];
}
int main()
{
    fastio;
    cin>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        f[i][i-1]=0;
        for(int j=i;j<=n;j++)
            f[i][j]=f[i][j-1]+arr[i];
    }
    sol();
}
