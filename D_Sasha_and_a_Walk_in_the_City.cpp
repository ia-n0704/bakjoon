# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define first x
#define second y
typedef long long ll;
const ll mod=998244353;
vector<int> v[300010];
ll dp[300010];
ll sum[300010];
int ch[300010];
ll num;
void dfs(int a)
{
    ch[a]=1;
    int cnt=0;
    for(int i=0;i<v[a].size();i++)
    {
        if(ch[v[a][i]]==0)
        {
            cnt++;
            dfs(v[a][i]);
        }
    }
    num+=max(0,cnt-1);
}
void sol()
{
    int n;
    cin>>n;
    num=0;
    ll res=1;
    for(int i=0;i<n;i++)
    {
        res*=2;
        res%=mod;
    }
    sum[3]=1;
    dp[3]=1;
    sum[4]=6;
    dp[4]=5;
    for(int i=5;i<=n;i++)
    {
        dp[i]=sum[i-1]+10*(i-4);
        sum[i]=sum[i-1]+dp[i];
    }
    int st;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(i==0) st=a;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(st);
    cout<<res-dp[n]+dp[num]<<'\n';
    for(int i=1;i<=n;i++)
        fill(v[i].begin(),v[i].end(),0);
    fill(ch,ch+n+1,0);
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