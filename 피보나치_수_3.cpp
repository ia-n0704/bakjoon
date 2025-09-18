# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n;
const ll mod=1e6;
const ll temp=15*(mod/10);
ll pi[temp+10];
int main()
{
    fastio;
    cin>>n;
    pi[1]=1;
    for(int i=2;i<=temp;i++)
        pi[i]=(pi[i-1]+pi[i-2])%mod;
    cout<<pi[n%temp];
}