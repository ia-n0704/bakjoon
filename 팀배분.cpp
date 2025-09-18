# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
vector<int> v[110];
int ch[110];
int n;
void dfs(int x,int color)
{
    ch[x]=color;
    for(auto i:v[x])
    {
        if(ch[i]==-1)
            dfs(i,color^1);
    }
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        for(int j=1;j<=a;j++)
        {
            int b;
            cin>>b;
            v[i].push_back(b);
        }
    }   
    fill(ch,ch+n+1,-1);
    for(int i=1;i<=n;i++)
        if(ch[i]==-1) dfs(i,0);
    vector<int> red,blue;
    for(int i=1;i<=n;i++)
    {
        if(ch[i]==0) red.push_back(i);
        else blue.push_back(i);
    }
    cout<<red.size()<<'\n';
    for(auto i:red) cout<<i<<" ";
    cout<<'\n';
    cout<<blue.size()<<'\n';
    for(auto i:blue) cout<<i<<" ";
}