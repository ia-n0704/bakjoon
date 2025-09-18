# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
double a,b,c;
int main()
{
    fastio;
    cin>>a>>b>>c;
    double l=1,r=max(a,b);
    while(l+0.0001<r)
    {
        double mid=(l+r)/2;
        double h1=sqrt((a*a-mid*mid));
        double h2=sqrt((b*b)-(mid*mid));
        double num=(h1*h2)/(h1+h2);
        if(num>=c) l=mid;
        else r=mid;
    }
    printf("%.3lf",l);
}