# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll dp[510][51000];
const ll mod=1e9+7;
int main()
{
    fastio;
    dp[1][0]=dp[1][1]=1;
    for(int i=2;i<=500;i++)
    {
        for(int j=0;j<=i*(i+1)/2;j++)
        {
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=mod;
            dp[i][j+i]+=dp[i-1][j];
            dp[i][j+i]%=mod;
        }
    }
    for(int i=1;i<=500;i++)
    {
        for(int j=1;j<=50000;j++)
        {
            dp[i][j]+=dp[i][j-1];
            dp[i][j]%=mod;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        ll res=0;
        ll a,b;
        cin>>a>>b;
        ll temp=max(a,b);
        a=min(a,b);
        b=temp;
        for(int i=1;i<=500;i++)
        {
            ll num=i*(i+1)/2;
            ll temp=num-b-1;
            if(a>=temp)
            {
                num=dp[i][a];
                if(temp>=0)
                    num-=dp[i][temp];
                res+=(num+mod);
                res%=mod; 
            }
            else break;
        }
        cout<<res<<'\n';
    }
}