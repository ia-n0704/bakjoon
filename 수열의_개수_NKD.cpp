# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
const ll mod=1e9+7;
ll dp1[200010];
ll dp2[200010];
int n,k,d;
int main()
{
    fastio;
    cin>>n>>k>>d;
    dp2[0]=1;
    for(int i=1;i<=k;i++)
    {
        for(int j=i;j<=min(100000,d+i);j++)
        {
            dp1[j]+=dp[j];
            dp1[j]%=mod;
        }
        for(int j=1;j<=d+i;j++)
            dp2[j]=dp1[j];
    }
    cout<<dp2[n];
}