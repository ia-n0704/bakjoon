# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll arr[300010],brr[300010];
void sol()
{
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>arr[i];
    for(ll i=1;i<=m;i++) cin>>brr[i];
    ll st=arr[1],stidx;
    sort(arr+1,arr+n+1);
    for(ll i=1;i<=n;i++)
    {
        if(arr[i]==st)
        {
            stidx=i;
            break;
        }
    }
    sort(brr+1,brr+m+1);
    vector<ll> v;
    for(ll i=1;i<=m;i++)
    {
        ll idx=lower_bound(arr+1,arr+n+1,brr[i])-arr;
        if(idx<=stidx) v.push_back(1);
        else v.push_back(n-idx+2);
    }
    sort(v.begin(),v.end());
    for(ll i=1;i<=m;i++)
    {
        ll res=0;
        for(ll j=i-1;j<v.size();j+=i)
            res+=v[j];
        cout<<res<<" ";
    }
    cout<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}