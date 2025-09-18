# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int t;
ll a,b,c;
int main()
{
    fastio;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        if(c==0 && b%2 && a<2) cout<<"No\n";
        else if(a>=c && (a+b*2+c*3)%2==0) cout<<"Yes\n";
        else cout<<"No\n";
    }
}