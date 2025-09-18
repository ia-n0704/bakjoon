# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll dp[3010][3010];
ll sum[3010];
int main()
{
    fastio;
    string s;
    cin>>s;
    int n=s.length()+1;
    for(int i=1;i<=n;i++) dp[1][i]=1;
    for(int i=1;i<=n;i++) sum[i]=i;
    for(int i=0;i<n-1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i]=='>')
                dp[i+2][j]=sum[n]-sum[j];
            else dp[i+2][j]=sum[j-1];
            cout<<dp[i+2][j]<<" ";
        }
        sum[0]=0;
        for(int j=1;j<=n;j++)
        {
            sum[j]=sum[j-1]+dp[i+2][j];
        }
        cout<<'\n';
    }
    cout<<sum[n];
}