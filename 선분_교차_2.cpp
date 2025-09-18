# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll x1,x2,x3,x4;
ll y,y2,y3,y4;
int ccw(pll a,pll b,pll c)
{
    ll C=(a.first*b.second+b.first*c.second+c.first*a.second)-(a.second*b.first+b.second*c.first+c.second*a.first);
    if(C>0) return 1;
    else if(C==0) return 0;
    else return -1;
}
int f(pair<pll, pll> l1, pair<pll, pll> l2) {
    pll a=l1.first;
    pll b=l1.second;
    pll c=l2.first;
    pll d=l2.second;
    ll ab=ccw(a,b,c)*ccw(a,b,d); 
    ll cd=ccw(c,d,a)*ccw(c,d,b); 
    //cout<<ab<<" "<<cd<<'\n';
    if (!ab && !cd)
    {
        if (a>b) swap(a,b);
        if (c>d) swap(c,d);
        return c<=b && a<=d;
    }
    return ab<=0 && cd<=0;
}
int main()
{
    fastio;
    cin>>x1>>y>>x2>>y2>>x3>>y3>>x4>>y4;
    cout<<f({{x1,y},{x2,y2}},{{x3,y3},{x4,y4}});
}