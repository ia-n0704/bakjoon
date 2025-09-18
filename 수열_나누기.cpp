# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int s,e;
pll cht[100010];
ll idx[100010];
ll sum[100010];
ll arr[100010];
ll dp1[100010],dp2[100010];
int check[210][100010];
int n,k;
double cross(int a,int b)
{
    return (double)(cht[a].second-cht[b].second)/(cht[b].first-cht[a].first);
}
ll f(ll x)
{
    return cht[s].first*x+cht[s].second;
}
void insert(pll x,ll b)
{
    cht[e]=x;
    idx[e]=b;
    while(s<e && cht[e].first==cht[e-1].first)
    {
        cht[e-1]=cht[e];
        idx[e-1]=idx[e];
        e--;
    }
    while(s+1<e && cross(e-2,e-1)>cross(e-1,e))
    {
        cht[e-1]=cht[e];
        idx[e-1]=idx[e];
        e--;
    }
    e++;
}
int main()
{
    fastio;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+arr[i];
    for(int i=1;i<=k;i++)
    {
        s=0;
        e=0;
        for(int j=i;j<=n;j++)
        {
            while(s+1<e && sum[j]*(cht[s].first-cht[s+1].first)<=cht[s+1].second-cht[s].second) s++;
            dp1[j]=f(sum[j]);
            check[i][j]=idx[s];
            insert({sum[j],dp2[j]-sum[j]*sum[j]},j);
        }
        for(int j=1;j<=n;j++)
            dp2[j]=dp1[j];
    }
    vector<int> res;
    int temp=n;
    for(int i=k;i>=1;i--)
    {
        res.push_back(check[i][temp]);
        temp=check[i][temp];
    }
    cout<<dp1[n]<<'\n';
    for(auto i:res) cout<<i<<" ";
}