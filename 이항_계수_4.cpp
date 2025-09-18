# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,mod,k;
ll arr[2010][2010];
ll go(ll n,ll k)
{
    if(arr[n%mod][k%mod]!=-1) return arr[n%mod][k%mod];
    if(n%mod==k%mod || k%mod==0) return arr[n%mod][k%mod]=1;
    return arr[n%mod][k%mod]=(go((n-1)%mod,(k-1)%mod)+go((n-1)%mod,k%mod))%mod;
}
int main()
{
    fastio;
    cin>>n>>k>>mod;
    for(int i=0;i<=mod;i++)
        for(int j=0;j<=mod;j++) arr[i][j]=-1;
    cout<<go(n%mod,k%mod);
}