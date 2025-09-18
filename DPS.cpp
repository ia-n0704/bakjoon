# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,s,e;
struct DPS
{
    double r,a,d;
}arr[100010];
double res;
int main()
{
    fastio;
    cin>>n>>s>>e;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].r>>arr[i].a>>arr[i].d;
        res+=e/(ll)(arr[i].r+arr[i].a)*arr[i].d;
        if(e%(ll)(arr[i].r+arr[i].a)-arr[i].r>0)
            res+=(e%(ll)(arr[i].r+arr[i].a)-arr[i].r)*arr[i].d/arr[i].a;
        res-=s/(ll)(arr[i].r+arr[i].a)*arr[i].d;
        if(s%(ll)(arr[i].r+arr[i].a)-arr[i].r>0)
            res-=(s%(ll)(arr[i].r+arr[i].a)-arr[i].r)*arr[i].d/arr[i].a;
    }
    cout<<fixed<<setprecision(8)<<res/(e-s);
}