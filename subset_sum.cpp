# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n,t;
int arr[5010];
int dp[5010][5010];
int main()
{
    fastio;
    cin>>n;
    cin>>t;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<arr[i];j++)
            dp[i][j]=dp[i-1][j];
        for(int j=arr[i];j<=t;j++)
            dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i]];
    }
    cout<<dp[n][t];
}
