# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n;
int main()
{
    fastio;
    cin>>n;
    for(ll i=1;i<=1000000;i++)
    {
        ll x=i;
        ll temp=x*x*x;
        if(temp<n) continue;
        temp=temp-n;
        ll l=1,r=min((ll)1e6,temp);
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(mid*mid*mid>=temp) r=mid-1;
            else l=mid+1;
        }
        //cout<<i<<" "<<l<<'\n';
        if(l*l*l==temp)
        {
            cout<<x<<" "<<l;
            //return 0;
        }
    }
    cout<<-1;
}