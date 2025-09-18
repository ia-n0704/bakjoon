# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
double x,y,d,t;
int main()
{
    fastio;
    cin>>x>>y>>d>>t;
    double dist=sqrt(x*x+y*y);
    int flag=0;
    double l=dist;
    while(l>=0)
    {
        flag++;
        l-=d;
    }
    flag--;
    l+=d;
    if(dist>=d)
        printf("%.13lf",min(dist,min(t*flag+l,(flag+(bool)l)*t)));
    else    
        printf("%.13lf",min(dist,min(t*2,t+d-dist)));
}