# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll arr[200010],sum[200010];
void sol()
{
    ll n;
    ll k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sum[i]=sum[i-1]+arr[i];
    }
    ll res=0;
    res=sum[n];
    res+=n*k;
    if(n==1)
    {
        cout<<sum[n]+k-1<<'\n';
        return;
    }
    if(k>=n)
    {
        res-=n*(n+1)/2;
        cout<<res<<'\n';
        return;
    }
    res=0;
    for(int i=k;i<=n;i++)
    {
        res=max(res,sum[i]-sum[i-k]);
    }
    cout<<res+k*(k-1)/2<<'\n';
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