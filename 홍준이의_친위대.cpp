# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int t;
ll dp[30][30];
int main()
{
    fastio;
    dp[1][0]=1;
    for(int i=2;i<=20;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(i%2)
            {
                for(int x=j;x<=i;x++)
                    dp[i][j]+=dp[i-1][x];
            }
            else
            {
                for(int x=0;x<=j-1;x++)
                    dp[i][j]+=dp[i-1][x];
            }
        }
    }
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<"1\n";
            continue;
        }
        ll res=0;
        for(int i=0;i<n;i++)
            res+=dp[n][i];
        cout<<res*2<<'\n';
    }
}
