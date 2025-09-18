# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
int n,m;
int arr[1010][1010][2];
int X[5]={-1,0,1,0};
int Y[5]={0,1,0,-1};
void bfs()
{
    queue<pair<pll,int>> q;
    q.push({{1,1},0});
    while(!q.empty())
    {
        auto a=q.front();
        int x=a.first.first,y=a.first.second;
        int flag=a.second;
        if(x==n && y==m)
        {
            cout<<arr[x][y][flag]+1;
            break;
        }
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+X[i];
            int ny=y+Y[i];
            if(nx<1 || ny<1 || nx>n || ny>m) continue;
            if(arr[nx][ny][0])
            {
                if(flag==0)
                {
                    arr[nx][ny][1]=arr[x][y][0]+1;
                    q.push({{nx,ny},1});
                }
            }
            else
            {
                if(flag==1 && arr[nx][ny][flag])  continue;
                arr[nx][ny][flag]=arr[x][y][flag]+1;
                q.push({{nx,ny},flag});
            }
        }        
    }
    if(q.empty())
        cout<<-1;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%1d",&arr[i][j]);
    bfs();
}