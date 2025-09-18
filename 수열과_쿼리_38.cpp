# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll res1,res2;
int main()
{
    fastio;
    int m;
    cin>>m;
    while(m--)
    {
        ll a,x;
        cin>>a;
        if(a==1)
        {
            cin>>x;
            res1+=x;
            res2^=x;
        }
        else if(a==2)
        {
            cin>>x;
            res1-=x;
            res2^=x;
        }
        else if(a==3)
            cout<<res1<<'\n';
        else cout<<res2<<'\n';
    }
}