# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,l;
pair<ll,ll> arr[240010];
pair<pair<ll,ll>,ll> brr[240010];
ll mx[240010][25];
bool compare(pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b)
{
    if(a.first.second==b.first.second) return a.first.first<b.first.first;
    return a.first.second<b.first.second;
}
int main()
{
    fastio;
    cin>>n>>l;
    for(ll i=1;i<=n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
        if(arr[i].first>arr[i].second) swap(arr[i].first,arr[i].second);
        if((arr[i].second-arr[i].first)*2>l) arr[i]={arr[i].second,arr[i].first+l};
        arr[n+i]={arr[i].first+l,arr[i].second+l};
    }
    sort(arr+1,arr+n*2+1);
    for(ll i=1;i<=2*n;i++)
        brr[i]={arr[i],i};
    sort(brr+1,brr+n*2+1,compare);
    ll idx=1;
    for(ll i=1;i<=2*n;i++)
    {
        while(idx<2*n && brr[i].first.second>=arr[idx].first) idx++;
        mx[brr[i].second][0]=idx;
    }
    mx[2*n+1][0]=2*n;
    for(ll i=1;i<=24;i++)
    {
        for(ll j=1;j<=2*n;j++)
        {
            mx[j][i]=mx[mx[j][i-1]][i-1];
        }
    }
    ll res=1e16;
    ll num,cur;
    //cout<<mx[6][0];
    for(ll i=1;i<=n;i++)
    {
        num=0;
        cur=i;
        for(ll j=24;j>=0;j--)
        {
            //cout<<cur<<" ";
            if(mx[cur][j]<i+n)
            {
                //cout<<i<<" "<<j<<" "<<cur<<'\n';
                cur=mx[cur][j];
                num+=(1<<j);
            }
        }
        //cout<<cur<<'\n';
        while(cur<i+n)
        {
            cur=mx[cur][0];
            num++;               
        }
        res=min(res,num);
    }
    cout<<res;
}