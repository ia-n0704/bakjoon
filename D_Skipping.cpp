# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll arr[400010];
int brr[400010];
int par[400010];
ll mx;
int _find(int x)
{
    if(par[x]==x) return x;
    return par[x]=_find(par[x]);
}
void _union(int x,int y)
{
    x=_find(x);
    y=_find(y);
    if(x==y) return;
    if(x>y) swap(x,y);
    par[y]=x;
}
void dfs(int x,ll co)
{
    //cout<<x<<" "<<co<<"\n";
    if(x==0)
    {
        mx=max(mx,co);
        return;
    }
    _union(x,x-1);

    //1 - submit
    dfs(_find(x),co+arr[x]);

    //2 - skip
    dfs(_find(brr[x]),co);
}
void sol()
{
    mx=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) cin>>brr[i];
    for(int i=1;i<=n;i++)
        par[i]=i;
    dfs(1,0);
    cout<<mx<<'\n';
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