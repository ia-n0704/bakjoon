#include <bits/stdc++.h>
using namespace std;
int res_row[5]={5,10,9,0};
int res_col[5]={17,8,11,48};
int ch[20];
int arr[10][10];
int pm[10][10]={1};
void dfs(int x,int y)
{
    if(y==4)
    {
        
    }
    if(x==4)
    {
        
    }
    for(int i=1;i<=16;i++)
    {
        if(ch[i])
        {
            ch[i]=1;
            arr[x][y]=i;
            dfs(x,y+1);
            arr[x][y]=0;
            ch[i]=0;
        }
    }
}
int main()
{
    fastio;
    dfs(1,1); 
}