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
int dp[5010][5010];
string s,t;
int n,m;
int main()
{
    fastio;
    cin>>s>>t;
    n=(int)s.length();
    m=(int)t.length();
    for(int i=0;i<=n;i++)
        dp[i][0]=i;
    for(int i=0;i<=m;i++)
        dp[0][i]=i;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int flag=0;
            if(s[i-1]!=t[j-1]) flag=1;
            dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+flag);
            cout<<dp[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<dp[n-1][m-1];
}
