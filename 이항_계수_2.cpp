#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod;
ll fac[10000010];
ll inv[10000010];
void sol()
{
    cout<<(fac[n]*inv[r]%mod)*inv[n-r]%mod<<'\n';
}
ll _pow(ll a,ll x)
{
    ll res=1;
    ll num=1;
    while(x)
    {
        if(x%2)
            res=res*a%mod;
        x/=2;
        a*=a;
        a%=mod;
        num%=mod;
        res%=mod;
    }
    return res%mod;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>n>>r>>mod;
    fac[0]=1;
    for(int i=1;i<=10000010;i++)
        fac[i]=fac[i-1]*i%mod;
    inv[10000010]=_pow(fac[10000010],mod-2);
    for(int i=10000010-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%mod;
    sol();
}