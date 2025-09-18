#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int n,m;
string s[3010];
int dist1[3010][3010];
int dist2[3010][3010];
int X[5]={-1,0,1,0};
int Y[5]={0,1,0,-1};
int sx,sy,jx,jy;
vector<pair<int,int>> t;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='T')
                t.push_back({i,j});
            if(s[i][j]=='S')
            {
                sx=i;
                sy=j;
            }
            if(s[i][j]=='J')
            {
                jx=i;
                jy=j;
            }
        }
    }
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dist1[i][j]=dist2[i][j]=1e9;

    queue<pair<pair<int,int>,int>> q;

    q.push({{jx,jy},0});
    dist1[jx][jy]=0;
    while(!q.empty())
    {
        auto a=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=a.x.x+X[i];
            int ny=a.x.y+Y[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m || s[nx][ny]=='#') continue;
            if(dist1[nx][ny]==1e9)
            {
                dist1[nx][ny]=a.y+2;
                q.push({{nx,ny},a.y+2});
            }
        }
    }
    int res=dist1[sx][sy];
    
    q.push({{sx,sy},0});
    dist2[sx][sy]=0;
    while(!q.empty())
    {
        auto a=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=a.x.x+X[i];
            int ny=a.x.y+Y[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m || s[nx][ny]=='#') continue;
            if(dist2[nx][ny]==1e9)
            {
                dist2[nx][ny]=a.y+1;
                q.push({{nx,ny},a.y+1});
            }
        }
    }
    for(int i=0;i<t.size();i++)
        res=min(res,dist1[t[i].x][t[i].y]+dist2[t[i].x][t[i].y]);
    cout<<(res==1e9?-1:res);
}