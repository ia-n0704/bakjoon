# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int dp[200010];
void sol()
{
    int n;
    cin>>n;
    cout<<dp[n]<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=200000;i++)
    {
        dp[i]=dp[i-1];
        int num=0;
        int t=i;
        while(t)
        {
            num+=t%10;
            t/=10;
        }
        dp[i]+=num;
    }
    while(t--)
    {
        sol();
    }
}