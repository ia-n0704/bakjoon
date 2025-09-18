# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
struct Q
{
    int a,b,co;
}arr[100];
int n;
int dp[1010][1010];
int remain[1010][1010];
int cnt[1010][1010];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i].a>>arr[i].b>>arr[i].co;
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            int sum=0;
            for(int k=1;k<=n;k++)
            {
                if(i>=arr[k].a || j>=arr[k].b)
                {
                    sum+=arr[k].co;
                    cnt[i][j]+=1;
                }
            }
            remain[i][j]=sum-i-j+2;
            if(i==1 && j==1) dp[i][j]=1;
            else if(dp[i-1][j]==1 && remain[i-1][j]>0)
                dp[i][j]=1;
            else if(dp[i][j-1]==1 && remain[i][j-1]>0)
                dp[i][j]=1;
        }   
    }
    int res=0;
    for(int i=1;i<=1000;i++)
        for(int j=1;j<=1000;j++)
            if(dp[i][j]==1) res=max(res,cnt[i][j]);
    cout<<res;
} 