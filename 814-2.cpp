# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int ch;
int X[10]={-1,-1,-1,0,1,1,1,0};
int Y[10]={-1,0,1,1,1,0,-1,-1};
int arr[10][15];
void check(int num,int x,int y)
{
    if(num==0)
    {
        ch=1;
        return;
    }
    for(int i=0;i<8;i++)
    {
        int nx=x+X[i];
        int ny=y+Y[i];
        if(nx<1 || nx>8 || ny<1 || ny>14) continue;
        if(arr[nx][ny]==num%10)
            check(num/10,nx,ny);
    }
}
int main()
{
    fastio;
    srand(time(NULL));
    while(1)
    {
        for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=14;j++)
            {
                int num=rand()%10;
                arr[i][j]=num;
            }
        }   
        int cnt=1;   
        while(1)
        {
            for(int i=1;i<=8;i++)
            {
                for(int j=1;j<=14;j++)
                {
                    if(arr[i][j]!=cnt%10) continue;
                    ch=0;
                    check(cnt/10,i,j);
                    if(ch) break;
                }
            }
            if(ch==0) break;
            else cnt++;
        }
        if(cnt>=40)
        {
            cout<<cnt<<'\n';
            break;
        }
    }
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=14;j++)
            cout<<arr[i][j];
        cout<<'\n';
    }
}