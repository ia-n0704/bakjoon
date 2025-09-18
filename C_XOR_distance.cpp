# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void sol()
{
    ll a,b,r,x=0;
    cin>>a>>b>>r;
    if(a<b) swap(a,b);
    x=a;
    x
    //cout<<a<<" "<<b<<" "<<x<<'\n';
    cout<<(a^x)-(b^x)<<'\n';
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