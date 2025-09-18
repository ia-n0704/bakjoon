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
int n,m;
int arr[51][51];
int sum[51][51];
int dp[51][51][51][51];
const int inf=1e9;
int go(int x1,int y1,int x2,int y2)
{
    if(x1==x2 && y1==y2)
        return 0;
    if(dp[x1][y1][x2][y2]!=inf) return dp[x1][y1][x2][y2];
    int num=sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
    for(int i=x1;i<x2;i++)
        dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2],go(x1,y1,i,y2)+go(i+1,y1,x2,y2)+num);
    for(int i=y1;i<y2;i++)
        dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2],go(x1,y1,x2,i)+go(x1,i+1,x2,y2)+num);
    return dp[x1][y1][x2][y2];
}
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>arr[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i][j];
            for(int l=1;l<=n;l++)
                for(int r=1;r<=m;r++)
                    dp[i][j][l][r]=inf;
        }
    }
    cout<<go(1,1,n,m);
}  
