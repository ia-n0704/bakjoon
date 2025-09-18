#include <bits/stdc++.h>
using namespace std;
int ch[15][15];
int arr[15][15];
int X[5]={-1,0,1,0};
int Y[5]={0,1,0,-1};
int chx,chy;

void reset()
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            arr[i][j]=0;
            ch[i][j]=0;
        }
    }
}
void go(int x,int y,int dir)
{ 
    if(x==chx && y==chy)
        dir--;
    else if(arr[x][y]==0)
    {
        arr[x][y]=1;
        dir++;
    }
    else if(arr[x][y]==1)
    {
        arr[x][y]=2;
        dir--;
    }
    else if(arr[x][y]==2)
    {
        if(ch[x][y]>=1000) return;
        else ch[x][y]++;
    }
    dir+=4;
    dir%=4;
    int nx=x+X[dir],ny=y+Y[dir];
    if(nx<0) nx=9;
    else if(nx>=10) nx=0;
    if(ny<0) ny=9;
    else if(ny>=10) ny=0;
    go(nx,ny,dir);
}
int main()
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            chx=i,chy=j;
            reset();
            go(0,0,0);
            int flag=0;
            for(int a=0;a<10;a++)
            {
                for(int b=0;b<10;b++)
                {
                    if(a==chx && b==chy) continue;
                    if(arr[a][b]!=2)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag) break;
            }
            if(!flag)
                cout<<i<<" "<<j<<'\n';
        }
    }
}