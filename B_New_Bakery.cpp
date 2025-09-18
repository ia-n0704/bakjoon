# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void sol()
{
    ll n,a,b;
    cin>>n>>a>>b;
    if(a>=b)
    {
        cout<<n*a<<'\n';
        return;
    }
    else
    {
        if(b-a>n)
        {
            cout<<b*(b+1)/2-(b-n)*(b-n+1)/2<<'\n';
        }
        else
        {
            n-=(b-a);
            ll res=b*(b+1)/2-a*(a+1)/2;
            res+=n*a;
            cout<<res<<'\n';            
        }
    }
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