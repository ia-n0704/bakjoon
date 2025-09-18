#include <bits/stdc++.h>
using namespace std;
int dp[1000010];
int main()
{
    srand(time(NULL));
    while(1)
    {
        int n,k;
        n=rand()%1000000+1;
        k=rand()%n+2;
        int cnt=0;
        int nn=n;
        while(n>1)
        {
            if(nn%k==0) nn/=k;
            else nn-=1;
            cnt++;
        }

        dp[1]=0;
        for(int i=2;i<=n;i++) dp[i]=n+1;
        for(int i=1;i<=n;i++)
        {
            if(i*k<=n) dp[i*k]=min(dp[i*k],dp[i]+1);
            dp[i+1]=min(dp[i+1],dp[i]+1);
        }
        if(cnt!=dp[n])
        {
            cout<<n<<" "<<k;
            break;
        }
    }
}