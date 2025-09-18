#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define x first
#define y second
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll ccw(pll a,pll b,pll c)
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
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<pll> v(n);
        for(int i=0;i<n;i++)
        {
            char c;
            cin>>v[i].x>>v[i].y;
        }
        v=Convex_Hull(v);
        cout<<v.size()<<'\n';
        reverse(v.begin(),v.end());
        int idx;
        int mxy=-1000,mnx;
        for(int i=0;i<v.size();i++)
        {
            if(mxy<v[i].y || (mxy==v[i].y && mnx>v[i].x))
            {
                idx=i;
                mxy=v[i].y;
                mnx=v[i].x;
            }
        }
        for(int i=idx;i<v.size();i++) cout<<v[i].x<<" "<<v[i].y<<'\n';
        for(int i=0;i<idx;i++) cout<<v[i].x<<" "<<v[i].y<<'\n';        
    }

}