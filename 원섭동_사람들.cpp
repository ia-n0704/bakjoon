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
int ch1[200010],ch2[200010];
int cnt[200010];
int num[200010];
int res;
int mx;
pair<int,int> arr[200010];
void dfs(int v,int c)
{
    if(ch2[v]) return;
    ch2[v]=1;
    num[v]+=c;
    if(arr[v].second<=num[v])
        dfs(arr[v].first,arr[v].second);
    else
        dfs(arr[v].first,0);
}
void dfs2(int v,int c)
{
    if(ch1[v]) return;
    ch1[v]=1;
    mx=max(mx,arr[v].second-c-num[v]);
    if(arr[v].second<=c+num[v])
        dfs(arr[v].first,arr[v].second);
    else
        dfs(arr[v].first,0);
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
        cnt[arr[i].first]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]==0)
        {
            ch1[i]=1;
            ch2[i]=1;
            num[arr[i].first]+=arr[i].second;
            res+=arr[i].second;
        }   
    }
    for(int i=1;i<=n;i++)
    {
        if(ch2[i]==0)
            dfs(i,0);
    }
    for(int i=1;i<=n;i++)
    {
        if(ch1[i]==0)
        {
            mx=0;
            dfs2(i,0);
            res+=mx;
        }
    }
    cout<<res;
}