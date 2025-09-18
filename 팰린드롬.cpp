# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int dp[2010][2010];
int n;
int arr[2010];
int m;
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) dp[i][i]=1;
    for(int i=1;i<=n-1;i++)
        if(arr[i]==arr[i+1]) dp[i][i+1]=1;
    for(int i=2;i<=n-1;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            int l=j,r=i+j;
            if(dp[l+1][r-1] && arr[l]==arr[r])
                dp[l][r]=1;
        }
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<dp[a][b]<<'\n';
    }
}