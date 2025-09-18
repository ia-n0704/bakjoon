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
ll arr[2010];
ll dp[2010][2010];
int n;
int main()
{
    fastio;
    cin>>n;
    int a,b;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        arr[i]=a;
    }
    arr[n+1]=b;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            int l=j,r=j+i-1;
            dp[l][r]=dp[l][l]+dp[l+1][r]+arr[l]*arr[l+1]*arr[r+1];
            for(int k=l+1;k<r;k++)
                dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+arr[l]*arr[k+1]*arr[r+1]);
        }
    }
    cout<<dp[1][n];
}
