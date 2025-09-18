# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int t;
int n;
int arr[100010][5];
int dp[100010][5];
int main()
{
    fastio;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=2;i<=n+1;i++) cin>>arr[i][1];
        for(int i=2;i<=n+1;i++) cin>>arr[i][2];
        for(int i=2;i<=n+1;i++)
        {
            dp[i][1]=max(dp[i-2][3],dp[i-1][2])+arr[i][1];
            dp[i][2]=max(dp[i-2][3],dp[i-1][1])+arr[i][2];
            dp[i][3]=max(dp[i][1],dp[i][2]);
        }
        cout<<dp[n+1][3]<<'\n';
    }   
}