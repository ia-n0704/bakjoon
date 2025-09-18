# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin,(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
pll arr[100010];
int n;
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
    return ab<=0 && cd<=0;
}

int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i].fi>>arr[i].se;
    for(int i=1;i<=3;i++)
    {
        pll x;
        cin>>x.fi>>x.se;
        int cnt=0;
        int flag=0;
        for(int j=1;j<=n;j++)
        {
            if(!ccw(x,arr[j],arr[j%n+1]))
                if(min(arr[j].fi,arr[j%n+1].fi)<=x.fi && max(arr[j].fi,arr[j%n+1].fi)>=x.fi && min(arr[j].se,arr[j%n+1].se)<=x.se && max(arr[j].se,arr[j%n+1].se)>=x.se)
                    flag=1;
            if(min(arr[j].se,arr[j+1].se)>x.se) continue;
            if(max(arr[j].se,arr[j+1].se)<=x.se) continue;
            if(f({x,{2e9,x.se}},{arr[j],arr[j%n+1]}))
                cnt++;
        }
        if(flag || cnt%2) cout<<"in\n";
        else cout<<"out\n";
    }
}
