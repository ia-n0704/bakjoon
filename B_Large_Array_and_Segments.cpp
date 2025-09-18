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
ll n,k,x;
ll arr[100010];
void sol()
{
    ll sum=0;
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum*k<x)
    {
        cout<<0<<'\n';
        return;
    }
    ll num=x/sum;
    x-=num*sum;
    ll res=n*k;
    res-=num*n;
    if(x==0) res++; 
    for(int i=n;i>=1;i--)
    {
        if(x-arr[i]<=0) break;
        res--;
        x-=arr[i];
    }
    cout<<max(0ll,res)<<'\n';
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