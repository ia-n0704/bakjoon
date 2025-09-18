# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e19;
vector<int> v[100010];
int sz[100010];
int ch[100010];
void dfs(int a)
{
    ch[a]=1;
    sz[a]=1;
    int flag=0;
    for(auto i:v[a])
    {
        if(ch[i]==0) 
            dfs(i);
        sz[a]+=sz[i];
    }
}
void dfs2(int a,int x)
{
    
}
void sol()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    for(int i=1;i<=n;i++) cout<<sz[i]<<'\n';
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