# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
struct GomGom
{
    ll x,y,z;
};
bool cmp(ll t,GomGom a)
{
    ll num=t%a.x;
    if(num>=a.y && num<=a.z) return true;
    else return false;
}
int main()
{
    fastio;
    GomGom a,b,c;
    cin>>a.x>>a.y>>a.z;
    cin>>b.x>>b.y>>b.z;
    cin>>c.x>>c.y>>c.z;
    ll lcm=a.x*b.x*c.x;
    ll res=lcm+1;
    for(ll i=a.y;i<=lcm;i+=a.x)
    {
        if(cmp(i,b) && cmp(i,c))
        {
            res=i;
            break;
        }
    }
    for(ll i=b.y;i<=lcm;i+=b.x)
    {
        if(cmp(i,a) && cmp(i,c))
        {
            res=min(res,i);
            break;
        }
    }
    for(ll i=c.y;i<=lcm;i+=c.x)
    {
        if(cmp(i,a) && cmp(i,b))
        {
            res=min(res,i);
            break;
        }
    }
    if(res>lcm) 
        cout<<-1;
    else cout<<res;
}