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
vector<int> v[200010];
int ch[200010];
set<pair<int,int>> s;
int num=200010;
void dfs(int x,int cnt)
{
    //cout<<x<<'\n';
    for(auto i:v[x])
    {
        if(i==1) num=min(num,cnt+1);
        if(ch[i]==1 || s.count({x,i}))
        {
            continue;
        }
        ch[i]=1;
        s.insert({x,i});
        dfs(i,cnt+1);
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
    }
    ch[1]=1;
    dfs(1,0);
    if(num==200010) num=-1;
    cout<<num;
}