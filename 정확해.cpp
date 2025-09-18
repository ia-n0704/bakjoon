# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
    fastio;
    ll a,b,n;
    cin>>a>>b>>n;
    b=a+b;
    ll ans=0;
    ll j;
    for(int i=1;i<=b;i=j+1)
    {
        j=n/(n/i);
        ans+=(j-i+1)*(n/i);
        ll num=i;
        int flag=0;
        for(int j=2;j<=n;j++)
        {
            num*=i;
            if(num>n)
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            ll t=n/(n/num);
            ans-=(t-num+1)*(n/num);
        }
    }
    cout<<ans;
}