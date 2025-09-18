# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define mod 998244353
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int dp[200010][500];
int T,n;
int main()
{
    fastio;
    dp[0][0]=1;
    for(int i=1;i<=200000;i++)
    {
        for(int j=1;j<=sqrt(200000);j++)
        {
            dp[i][j]+=dp[i-1][j-1];
            if(i-j>=0) dp[i][j]+=dp[i-j][j];
            dp[i][j]%=mod;
        }
    }
    cin>>T;
    while(T--)
    {
        cin>>n;
        ll res=0;
        for(int i=1;i*i<=n;i++)
        {
            if((n-i*i)%2==0)
            {
                res+=dp[(n-i*i)/2+i][i];
                res%=mod;
            }
        }
        cout<<res<<'\n';
    }
}