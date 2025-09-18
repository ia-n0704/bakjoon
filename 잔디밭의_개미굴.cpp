# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n;
vector<ll> v[300010];
ll ch[300010][2];
ll dp[300010][2];
ll ans[300010];
ll cnt;
void go(ll node,ll c)
{
    dp[node][1]=1;
    for(auto i:v[node])
    {
        if(c!=i)
        {
            go(i,node);
            dp[node][1]+=dp[i][0];
            dp[node][0]+=max(dp[i][0],dp[i][1]);
        }
    }
}
void dfs(ll node,ll c,ll num){
	if(ch[node][num]) return;
	ch[node][num]=1;
	cnt-=(num^1);
	for(auto i:v[node]){
		if(i!=c)
        {
            if(num || dp[i][0]>=dp[i][1]) 
                dfs(i,node,0);
            if(!num && dp[i][0]<=dp[i][1])
                dfs(i,node,1);            
        }
	}
}
int main()
{
    fastio;
    cin>>n;
    cnt=n;
    for(int i=1;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    go(1,0);
    ll num=n*(n-1)/2;
    if(dp[1][0]>=dp[1][1])
        dfs(1,0,0);
    if(dp[1][0]<=dp[1][1]) 
        dfs(1,0,1);
    cout<<num-cnt*(cnt-1)/2;
}