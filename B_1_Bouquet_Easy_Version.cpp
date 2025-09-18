# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll arr[200010];
ll sum[200010];
void sol()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+arr[i]; 
    ll l=1;
    ll mx=0;
    for(int i=1;i<=n;i++)
    {
        while(arr[i]-arr[l]>1 || sum[i]-sum[l-1]>m)
        {
            if(i==l) break;
            l++;
        }
        if(sum[i]-sum[l-1]<=m) mx=max(mx,sum[i]-sum[l-1]);
    }
    cout<<mx<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}