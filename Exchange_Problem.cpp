# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int dp[200010];
int n;
int arr[110];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    fill(dp+1,dp+200001,(int)1e9);
    for(int i=0;i<=200000;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i+arr[j]>200000) continue;
            if(dp[i]+1<dp[i+arr[j]]) dp[i+arr[j]]=dp[i]+1;
        }
    }
    int flag=0;
    for(int i=1;i<=200000;i++)
    {
        int num=i;
        int res=0;
        for(int j=n;j>=1;j--)
        {
            res+=num/arr[j];
            num%=arr[j];
        }
        if(num!=0) res=1e9;
        if(res>dp[i]) flag=1;
        //cout<<i<<" | "<<res<<" "<<dp[i]<<'\n';
    }
    if(flag) cout<<"No";
    else cout<<"Yes";
}