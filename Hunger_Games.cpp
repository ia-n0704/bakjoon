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
int arr[100],brr[100];
int dp[5010];
int w;
int main()
{
    fastio;
    cin>>t;
    while(t--)
    {
        cin>>n>>w;
        for(int i=1;i<=n;i++ ) cin>>arr[i];
        for(int i=1;i<=n;i++) cin>>brr[i];
        fill(dp,dp+w+1,0);
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=w;j>=0;j--)
            {
                int nx=j+arr[i];
                int co=dp[j]+brr[i];
                if(nx<=w && dp[nx]<co)
                    dp[nx]=co;
            }
        }
        for(int i=0;i<=w;i++) mx=max(mx,dp[i]);
        cout<<mx<<'\n';
    }
}