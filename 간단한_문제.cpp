# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll arr[100],brr[100];
void go(ll n,ll m,int st,int en)
{
    if(m==1)
        brr[st]=n*arr[st];
    else if(n%2)
    {
        brr[st]=n*arr[st];
        go((n+1)/2,m-1,st+1,en);
    }
    else
    {
        brr[en]=arr[en]*((1ll<<m)+n-2);
        go(n/2,m-1,st,en-1); 
    }
}
int main()
{
    ll n;
    ll m;
    fastio;
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>arr[i];
    go(n,m,1,m);
    for(int i=1;i<=m;i++) cout<<brr[i]<<" ";
}