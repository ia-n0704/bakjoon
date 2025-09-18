# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m;
vector<int> v[100010];
int ch[100010];
int mn=(int)1e9;
void dfs(int a,int cnt,int flag,int st,int par)
{
    for(auto i:v[a])
    {
        if(i==par) continue;
        if(ch[i])
        {
            mn=min(mn,cnt+1-ch[i]);
            continue;
        }
        ch[i]=cnt+1;
        dfs(i,cnt+1,1,st,a);
        ch[i]=0;
    }
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
    dfs(1,0,0,1,0);
    if(mn==(int)1e9) cout<<0;
    else 
        cout<<mn;
}