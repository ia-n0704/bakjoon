# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m;
int main()
{
    fastio;
    cin>>n>>m;
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        ll a;
        cin>>a;
        res+=a;
    }
    for(int i=1;i<=m;i++)
    {
        ll a;
        cin>>a;
        if(a) res*=a;
    }
    cout<<res;
}