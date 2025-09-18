# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef long long ll;
void Y()
{
    cout<<"YES\n";
}
void N()
{
    cout<<"NO\n";
}
void sol()
{
    ll a,b,l;
    set<ll> s;
    cin>>a>>b>>l;
    ll x=0,y=0;
    int cnt=0;
    do
    {
        if(ll(pow(b,y))*ll(pow(a,x))>l)
        {
            x++;
            y=0;
        }
        if(ll(pow(a,x))>l) break;
        if(l%(ll(pow(a,x))*ll(pow(b,y)))==0)
            s.insert(l/(ll(pow(a,x))*ll(pow(b,y))));
        //cout<<ll(pow(a,x))*ll(pow(b,y))<<'\n';
        y++;
    } while(ll(pow(a,x))<=l);
    cout<<s.size()<<'\n';
    
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        sol();
}