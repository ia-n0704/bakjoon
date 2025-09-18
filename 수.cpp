# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n;
const ll mx=1e18;
map<ll,ll> dp;
ll l[100];
ll _pow(ll a,ll x)
{
    ll res=1;
    while(x)
    {
        if(x%2) res*=a;
        x/=2;
        a*=a;
    }
    return res;
}
ll f(ll x,ll k,ll mx)
{
    ll l=1,r=mx;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        ll temp=_pow(mid,k);
        if(temp<x) l=mid+1;
        else r=mid-1;
    }
    return l;
}
ll find_limit(ll x)
{
    ll l=2,r=mx;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(x*log(mid)+1e-9<=log(mx)) l=mid+1;
        else r=mid-1;
    }
    return r;
}
ll go(ll x)
{
    //cout<<x<<'\n';
    if(x==1) return 0;
    if(dp[x]) return dp[x];
    dp[x]=x-1;
    for(int i=1;i<=61;i++)
    {
        ll b=f(x,i,l[i]);
        ll a=b-1;
        ll anum=_pow(a,i);
        ll bnum=_pow(b,i);
        //cout<<a<<" "<<b<<" "<<anum<<" "<<bnum<<'\n';
        if(a-1 && mx>abs(x-_pow(a,i)))
            dp[x]=min(dp[x],go(a)+x-anum+1);
        if(b-1 && mx>abs(x-_pow(b,i)))
            dp[x]=min(dp[x],go(b)+bnum-x+1);
    }
    return dp[x];
}
int main()
{
    fastio;
    for(int i=2;i<=61;i++)
        l[i]=find_limit(i);
    //for(int i=2;i<=61;i++) cout<<l[i]<<" ";
    cin>>n;
    cout<<go(n);
}