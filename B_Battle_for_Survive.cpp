# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll arr[200010];
void sol()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    ll sum=0;
    for(int i=1;i<n-1;i++) sum+=arr[i];
    sum-=arr[n-1];
    cout<<arr[n]+sum<<'\n';
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