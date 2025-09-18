# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define mod 1000000007
int dp[310][1<<18];
int n,m;
int get_dp(int x,int bit)
{
    if(x==n*m) return 1;
    if(dp[x][bit]!=-1) return dp[x][bit];

    dp[x][bit]=get_dp(x+1,bit>>1)%mod;
    if(x%m==0 || (bit&1)==0 || (bit&2)==0 || (bit&(1<<m))==0)
        dp[x][bit]+=get_dp(x+1,(bit>>1)+(1<<m))%mod;
    return dp[x][bit]%mod;
}
int main()
{
    fastio;
    cin>>n>>m;
    if(n<m) swap(n,m);
    for(int i=0;i<=n*m;i++)
        for(int j=0;j<(1<<(m+1));j++)
            dp[i][j]=-1;
    cout<<get_dp(0,0);
}