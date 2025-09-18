# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
pair<pll,pll> arr[200010];
int par[200010];
int cnt[200010];
int parent(int x)
{
    if(par[x]==x) return x;
    return par[x]=parent(par[x]);
}
void _union(int x,int y)
{
    int par_x=parent(x);
    int par_y=parent(y);
    if(par_x==par_y) return;
    if(par_x<par_y) 
    {
        cnt[par_x]+=cnt[par_y];
        par[par_y]=par_x;
    }
    else
    {
        cnt[par_y]+=cnt[par_x];
        par[par_x]=par_y;
    }
}
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
    cin>>n;
    fill(cnt+1,cnt+n+1,1);
    for(int i=1;i<=n;i++) cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second.first>>arr[i].second.second;
    for(int i=1;i<=n;i++) par[i]=i;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(f(arr[i],arr[j])) 
            {
                _union(i,j);
            }
        }
    }
    set<int> s;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        mx=max(mx,cnt[i]);
        s.insert(parent(i));
    }
    cout<<s.size()<<'\n';
    cout<<mx;
}