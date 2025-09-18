# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll dp[100010];
ll f[100010];
void sol()
{
    int n;cin>>n;
    cout<<(dp[n]*f[n])%mod<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dp[2]=2;
    f[1]=1;
    for(ll i=2;i<=100000;i++) f[i]=(f[i-1]*i)%mod;
    for(ll i=3;i<=100000;i++)
        dp[i]=(dp[i-1]+(i-1)*2)%mod;
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}