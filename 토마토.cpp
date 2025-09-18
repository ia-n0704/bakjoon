# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
struct T
{
    int x,y;
};
int X[5]={-1,0,1,0};
int Y[5]={0,1,0,-1};
int ch[1010][1010];
int arr[1010][1010];
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    queue<T> q;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==1)
                q.push({i,j});
        }
    }
    int res=0;
    while(!q.empty())
    {
        T a=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=a.x+X[i];
            int ny=a.y+Y[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n && arr[nx][ny]==0 && ch[nx][ny]==0)
            {
                q.push({nx,ny});
                ch[nx][ny]=ch[a.x][a.y]+1;
            }
        }
    }
    int flag=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==0 && ch[i][j]==0) flag=1;
            res=max(res,ch[i][j]);
        }
    }
    if(flag) cout<<-1;
    else cout<<res;
}