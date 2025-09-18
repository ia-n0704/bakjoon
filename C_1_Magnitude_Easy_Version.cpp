# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll,ll> dp[200010];
ll arr[200010];
void sol()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    dp[1]={arr[1],abs(arr[1])};
    for(int i=2;i<=n;i++)
    {
        dp[i].first=dp[i-1].first+arr[i];
        dp[i].second=max(dp[i-1].second+arr[i],abs(dp[i-1].first+arr[i]));
    }
    cout<<dp[n].second<<'\n';
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