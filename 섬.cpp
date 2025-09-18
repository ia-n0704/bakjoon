# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int X[10]={-1,0,1,0,-1,1,1,-1};
int Y[10]={0,1,0,-1,1,1,-1,-1};
string s[2010];
int landch[2010][2010];
int waterch[2010][2010];
int safety[2000*2000];
int n,m;
int cnt;
void land_dfs(int x,int y)
{
    landch[x][y]=cnt;
    for(int i=0;i<4;i++)
    {
        int nx=x+X[i],ny=y+Y[i];
        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
        if(s[nx][ny]=='#' && landch[nx][ny]==0) land_dfs(nx,ny);
    }
}
void water_dfs(int x,int y)
{
    waterch[x][y]=1;
    for(int i=0;i<8;i++)
    {
        int nx=x+X[i],ny=y+Y[i];
        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
        if(i<4 && s[nx][ny]=='#') safety[landch[nx][ny]]=1;
        else if(i>=4 && s[nx][ny]=='.' && waterch[nx][ny]==0 && s[nx][y]=='#' && s[x][ny]=='#' && landch[nx][y]!=landch[x][ny]) water_dfs(nx,ny);
        else if(i<4 && s[nx][ny]=='.' && waterch[nx][ny]==0) water_dfs(nx,ny);
    }  
}
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>s[i];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='#' && landch[i][j]==0)
            {
                cnt++;
                land_dfs(i,j);
            }
        }
    }
    water_dfs(0,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='.') cout<<'.';
            else if(safety[landch[i][j]]) cout<<'O';
            else cout<<'X';
        }
        cout<<'\n';
    }
}