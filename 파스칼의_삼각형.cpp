#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int main()
{
    dp[1][1]=1;
    for(int i=2;i<=50;i++)
        for(int j=1;j<=i;j++)
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
    int n,k;
    cin>>n>>k;
    cout<<dp[n][k];
}