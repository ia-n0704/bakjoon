# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e16;
void sol()
{
    ll n,p,l,t;
    cin>>n>>p>>l>>t;
    ll num=(n-1)/7+1;
    ll res=p/(l+t*2);
    if(p%(l+t*2))
        res++;
    ll ans=0;
    if(num/2>=res)
    {
        cout<<n-res<<'\n';
        return;
    }
    ans=(p-(num/2)*(l+t*2))/l;
    if((p-(num/2)*(l+t*2))%l)
        ans++;
    cout<<n-ans-(num/2)<<'\n';
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