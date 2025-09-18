# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll inf=1e16;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m;
int arr[110][110];
int ch[110][110];
int X[5]={-1,0,1,0};
int Y[5]={0,1,0,-1};
void dfs(int a,int b,int co)
{
    if(a<1 || b<1 || a>n || b>m || ch[a][b]<=co)
        return;
    ch[a][b]=co;
    //cout<<a<<" "<<b<<" "<<co<<'\n';
    for(int i=0;i<4;i++)
    {
        int na=a+X[i];
        int nb=b+Y[i];
        if(na<1 || nb<1 || na>n || nb>m)
            continue;
        int nco=co+arr[na][nb];
        dfs(na,nb,nco);
    }
}
int main()
{
    fastio;
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%1d",&arr[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ch[i][j]=inf;
    dfs(1,1,arr[1][1]);
    printf("%d",ch[n][m]);
}