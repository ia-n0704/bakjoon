# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin,(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n,m;
vector<int> v[5010];
int dp[5010][1010];
int ch[5010];
void _update(int x,int bbomi,int time)
{
    int flag=0;
    ch[x]=1;
    if(x==bbomi) flag++;
    dp[x][time]=max(dp[x][time],dp[x][time-1]+flag);
    for(auto i:v[x])
    {
        int temp=0;
        if(i==bbomi) temp=1;
        dp[i][time]=max(dp[i][time],dp[x][time-1]+temp);
        if(ch[i]==0) _update(i,bbomi,time);
    }
}
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=m;i++)
    {
        int a;
        cin>>a;
        _update(1,a,i);
        fill(ch,ch+n+1,0);
    }
    int res=0;
    for(int i=1;i<=n;i++)
        res=max(res,dp[i][m]);
    cout<<res;
}
