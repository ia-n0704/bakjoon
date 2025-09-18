#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=2,j;i<=n;i=j+1)
    {
        j=n/(n/i);
        ans+=(n/i-1)*((j*(j+1)/2-i*(i-1)/2)%1000000);
        ans%=1000000;
    }
    cout<<ans;
}