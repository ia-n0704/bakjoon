# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
pair<int,int> v[500010];
int n;
void dfs1(int x)
{
    cout<<x<<' ';
    if(v[x].first) dfs1(v[x].first);
    if(v[x].second) dfs1(v[x].second);
}
void dfs2(int x)
{
    if(v[x].first) dfs2(v[x].first);
    cout<<x<<' ';
    if(v[x].second) dfs2(v[x].second);
}
void dfs3(int x)
{
    if(v[x].first) dfs3(v[x].first);
    if(v[x].second) dfs3(v[x].second);
    cout<<x<<' ';
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[i].first=a;
        v[i].second=b;
    }
    dfs1(1);
    cout<<'\n';
    dfs2(1);
    cout<<'\n';
    dfs3(1);
}