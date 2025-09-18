# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
ll n,k;
ll arr[200010];
ll sum[200010];
void sol()
{
    cin>>k>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]==k) arr[i]--;
    }
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+arr[i];
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        ll l=lower_bound(arr+i+1,arr+n+1,k-arr[i])-arr;
        ll r=lower_bound(arr+i+1,arr+n+1,k-1)-arr;
        ll bound=max(0ll,r-l);
        res+=(sum[r-1]-sum[l-1]+arr[i]*bound-(k-1)*bound)*2;
        res+=(n-r+1)*arr[i]*2;
        //cout<<l<<" "<<r<<" | ";
        //cout<<res<<'\n';
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