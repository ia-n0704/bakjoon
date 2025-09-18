# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
vector<int> v[1000010];
int check[1000010];
int dp[1000010][2];
int go(int node,int c)
{
    if(dp[node][c]!=-1) return dp[node][c];
    check[node]=1;
    dp[node][c]=c;
    for(auto i:v[node])
    {
        if(check[i]==0)
        {
            if(c==0)
                dp[node][c]+=go(i,1);
            else
                dp[node][c]+=min(go(i,0),go(i,1));
        }
    }
    check[node]=0;
    return dp[node][c];
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(dp,-1,sizeof dp);
    int mn=go(1,0);
    fill(check,check+n+1,0);
    memset(dp,-1,sizeof dp);
    mn=min(mn,go(1,1));
    cout<<mn;
}