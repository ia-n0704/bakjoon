# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
void sol()
{
    cin>>n;
    ll cnt=0;
    ll k=n;
    while(k)
    {
        cnt++;
        k/=10;
    }
    k=0;
    for(ll i=0;i<cnt;i++)
        k+=4ll*(ll)pow(10ll,i);
    ll res=0;
    ll num=0;
    for(ll i=0;i<cnt-2;i++)
    {
        num+=5*(ll)pow(10ll,i);
        res+=num;
    }
    if(cnt!=1) res+=max(0ll,min(n,(ll)pow(10ll,cnt-1)*5ll-1)-k);
    cout<<res<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}