# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
int arr[10010];
int dp[10010],temp[10010];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(j==1) dp[j]=arr[i-1];
            else dp[j]=min(temp[j-1],temp[i-j]+arr[i-1]);
        }
        for(int j=1;j<=i;j++) temp[j]=dp[j];
    }
    cout<<dp[n/2];
}