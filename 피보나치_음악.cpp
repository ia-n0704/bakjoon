# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll mod;
int q;
string s;
int main()
{
    fastio;
    cin>>q>>mod;
    ll a=1,b=1;
    while(1)
    {
        s+=to_string(a);
        ll c=(a+b)%mod;
        a=b;
        b=c;
        if(!a && b==1)
            break;
    }
    s+='0';
    mod=s.length();
    while(q--)
    {
        ll num;
        cin>>num;
        cout<<s[(num-1)%mod]<<'\n';
    }
}