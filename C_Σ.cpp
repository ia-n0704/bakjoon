# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
set<ll> s;
int main()
{
    fastio;
    ll n,k,a;
    cin>>n>>k;
    ll num=k*(k+1)/2;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a<=k && !s.count(a))
        {
            num-=a;
            s.insert(a);
        }
    }
    cout<<num;
}