# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> plf;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
struct point
{
    double x,y;
};
point arr[100010];
point p;
int n;
int ccw(point p1, point p2, point p3)
{
    double temp = (p1.x*p2.y+p2.x*p3.y+p3.x*p1.y)-(p1.y*p2.x+p2.y*p3.x+p3.y*p1.x);
    if(temp>0)
        return 1;
    else if(temp<0)
        return -1;
    else
        return 0;
}
double dist(point p1, point p2)
{
    double d1=(p1.x-p2.x);
    double d2=(p1.y-p2.y);
    return sqrt(d1*d1+d2*d2);
}
bool cmp(point u,point v)
{
    int temp=ccw(p,u,v);
    if (!temp)
        return dist(p,u)<=dist(p,v);
    return temp==1;
}
int main()
{
    fastio;
    cin>>n;
    double mn=1e18;
    for(int i=1;i<=n;i++) cin>>arr[i].x>>arr[i].y;
    p=arr[1];
    sort(arr+2,arr+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        auto a=arr[i],b=arr[i%n+1];
        mn=min(mn,dist(a,b));
    }
    cout<<fixed<<setprecision(2)<<mn;
}