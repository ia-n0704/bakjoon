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
vector<int> v[10010];
int arr[10010];
int check[10010];
int dp[10010][2];
int ans[10010];
int go(int node,int c)
{
    if(dp[node][c]!=-1) return dp[node][c];
    check[node]=1;
    dp[node][c]=c*arr[node];
    for(auto i:v[node])
    {
        if(check[i]==0)
        {
            if(c==1)
                dp[node][c]+=go(i,0);
            else
            {
                int a=go(i,0);
                int b=go(i,1);
                dp[node][c]+=max(a,b);
            }
        }
    }
    check[node]=0;
    return dp[node][c];
}
int ch[10010];
void dfs(int node,int c)
{
    int flag=1;
    ch[node]=1;
    if(c==1 && dp[node][0]<dp[node][1])
    {
        ans[node]=1;
        flag=0;
    }
    for(auto i:v[node])
    {
        if(ch[i]==0)
        {
            dfs(i,flag);
        }
    }
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    v[0].push_back(1);
    memset(dp,-1,sizeof dp);
    int mn=go(0,0);
    cout<<mn<<'\n';
    dfs(0,0);
    for(int i=1;i<=n;i++)
    {
        if(ans[i]) cout<<i<<" ";
    }
}