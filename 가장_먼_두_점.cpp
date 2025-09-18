#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define x first
#define y second
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll dist(pll a,pll b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
double ccw(pll a,pll b,pll c)
{
    return (a.x*b.y+b.x*c.y+c.x*a.y)-(a.y*b.x+b.y*c.x+c.y*a.x);
}
vector<pll> Convex_Hull(vector<pll> v)
{
    sort(v.begin(),v.end());
    vector<pll> ans1,ans2,res;
    for(auto i:v)
    {
        while(ans1.size()>=2 && ccw(ans1.end()[-2],ans1.end()[-1],i)<=0) ans1.pop_back();
        ans1.push_back(i);
        while(ans2.size()>=2 && ccw(ans2.end()[-2],ans2.end()[-1],i)>=0) ans2.pop_back();
        ans2.push_back(i);
    }
    res=ans1;
    for(int i=ans2.size()-2;i>=1;i--)
        res.push_back(ans2[i]);
    return res;
} 
int main()
{
    fastio;
    int n; cin>>n;
    vector<pll> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i].x>>v[i].y;
    v=Convex_Hull(v);
    int temp=0;
    ll mx=0;
    n=v.size();
    for(int i=0;i<n;i++)
    {
        pll a;
        a.x=v[(temp+1)%n].x-v[temp%n].x+v[(i+1)%n].x;
        a.y=v[(temp+1)%n].y-v[temp%n].y+v[(i+1)%n].y;
        while(temp<n*2 && ccw(v[i],v[(i+1)%n],a)>=0)
        {
            mx=max(mx,dist(v[i],v[temp%n]));
            temp++;
            a.x=v[(temp+1)%n].x-v[temp%n].x+v[(i+1)%n].x;
            a.y=v[(temp+1)%n].y-v[temp%n].y+v[(i+1)%n].y;
        }
        mx=max(mx,dist(v[i],v[temp%n]));
    }
    cout<<mx;
}