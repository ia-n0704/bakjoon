# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b,c;
int dp[1010][1010];
void sol()
{
    cin>>a>>b>>c;
    int n=(int)a.length();
    int m=(int)b.length();
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            dp[i][j]=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            int A=0,B=0;
            if(i!=0 && a[i-1]==c[i+j-1]) A=1;
            if(j!=0 && b[j-1]==c[i+j-1]) B=1;
            if(i!=0) dp[i][j]=dp[i-1][j]+A;
            if(j!=0) dp[i][j]=max(dp[i][j],dp[i][j-1]+B);
            //cout<<dp[i][j]<<" ";
        }
        //cout<<'\n';
    }
    cout<<n+m-dp[n][m]<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}