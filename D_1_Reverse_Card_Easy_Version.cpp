# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void sol()
{
    ll n,m;
    ll res=0;
    cin>>n>>m;
    for(int i=1;i<=min(n,m);i++)
    {
        ll l,r;
        l=ceil((1/(double)i+1)/(double)i);
        r=floor((n/(double)i+1)/(double)i);
        res+=(r-l+1);
    }
    cout<<res<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}