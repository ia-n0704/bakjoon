# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
vector<int> v[20010];
int ch[20010];
int n,m;
int flag;
void dfs(int x,int color)
{
    ch[x]=color;
    for(auto i:v[x])
    {
        if(ch[i]==-1)
            dfs(i,color^1);
        else if(ch[i]==color)
            flag=1;
    }
}
int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            ch[i]=-1;
            v[i].clear();
        }
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        flag=0;
        for(int i=1;i<=n;i++)
            if(ch[i]==-1) dfs(i,0);
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
}