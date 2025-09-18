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
int n,a,b;
int dp[5010][110];
int main()
{
    fastio;
    cin>>n>>a>>b;
    int res=0;
    for(int i=0;i<=a;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=1e9;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        for(int j=a;j>=x;j--)
        {
            for(int k=i;k>=1;k--)
            {
                if(dp[j-x][k-1]==1e9) continue;
                dp[j][k]=min(dp[j][k],dp[j-x][k-1]+y);
                if(dp[j][k]<=b) res=max(res,k);
            }
        }   
    }
    cout<<res;
}
