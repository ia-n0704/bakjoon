# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,k,x;
int main()
{
    fastio;
    cin>>n>>k>>x;
    int num;
    if(x==1) num=1;
    else if(x<=3) num=2;
    else if(x<=7) num=3;
    else num=4;
    ll res=(n+1-num)-3*(k-1);
    if(x==4 || x==8 || x==9) res++;
    cout<<res;
}