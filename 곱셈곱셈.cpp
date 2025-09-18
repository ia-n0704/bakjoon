# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

ll power(ll a,ll b,ll m)
{
    if(b<=1) return a%m;
    ll num=power(a,b/2,m);
    if(b%2)
        return num*num*a%m;
    else return num*num%m;
}
int main()
{
    fastio;
    ll a,b,m;
    cin>>a>>b>>m;
    cout<<power(a%m,b%m,m)%m;
}