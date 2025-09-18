# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
const int mx=1e9;
int n,k;
int arr[101];
int dp[101][101][10];
int go(int l,int r,int num)
{
    if(l>r) return 0;
    if(l==r) return k-num-1;
    if(dp[l][r][num]!=mx) return dp[l][r][num];
    if(num==k-1) dp[l][r][num]=go(l+1,r,0);
    else if(num<k-1) dp[l][r][num]=go(l,r,num+1)+1;
    for(int i=l+1;i<=r;i++)
        dp[l][r][num]=arr[l]==arr[i]?min(dp[l][r][num],go(l+1,i-1,0)+go(i,r,num+1>k-1?k-1:num+1)):dp[l][r][num];
    return dp[l][r][num];
}
int main()
{
    fastio;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int r=0;r<=k;r++) dp[i][j][r]=mx;
    cout<<go(1,n,0);
}