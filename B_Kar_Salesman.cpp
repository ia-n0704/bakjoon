# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll arr[500010];
ll sum;
void sol()
{
    cin>>n>>m;
    sum=0;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++)
    {
        sum+=arr[i];
    }   
    cout<<max(arr[n],sum/m+(bool)(sum%m))<<'\n';
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