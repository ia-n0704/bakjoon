# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b;
ll arr[100010];
ll gcd(ll a,ll b)
{
    while(b)
    {
        ll r=a%b;
        a=b;
        b=r;
    }
    return a;
}
void sol()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++) cin>>arr[i];
    ll temp=gcd(a,b);
    for(int i=1;i<=n;i++)
        arr[i]%=temp;
    sort(arr+1,arr+n+1);
    ll res=arr[n]-arr[1];
    ll mn=arr[1],mx=arr[n];
    for(int i=1;i<n;i++)
    {
        arr[i]+=temp;
        mx=arr[i];
        mn=arr[i+1];
        res=min(res,mx-mn);
    }
    cout<<res<<'\n';
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