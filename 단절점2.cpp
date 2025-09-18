# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
vector<int> v[100010];
int n,m;
int ch[100010];
int cut[100010];
int cnt;
int dfs(int x,int root)
{
    ch[x]=++cnt;
    int res=ch[x];
    int num=0;
    for(auto i:v[x])
    {
        if(ch[i])
        {
            res=min(res,ch[i]);
            continue;
        }
        num++;
        int temp=dfs(i,0);
        res=min(res,temp);
        if(!root && temp>=ch[x]) cut[x]=1;
    }
    if(root && num>=2)
        cut[x]=1;
    return res;
}
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        if(ch[i]==0) dfs(i,1);
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        if(cut[i]) cout<<1;
        else cout<<0;
    }
 }