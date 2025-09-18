# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
string s[100];
int arr[100][100];
int brr[100][100];
int cnt;
int X[5]={-1,0,1,0};
int Y[5]={0,1,0,-1};
void push(int x,int y)
{
    cnt++;
    brr[x][y]^=1;
    for(int i=0;i<4;i++)
    {
        int nx=x+X[i];
        int ny=y+Y[i];
        if(nx<0 || ny<0 || nx>=10 || ny>=10) continue;
        brr[nx][ny]^=1;
    }
}
int main()
{
    fastio;
    int mn=(int)1e9;
    for(int i=0;i<10;i++)
    {
        cin>>s[i];
        for(int j=0;j<10;j++)
            arr[i][j]=(s[i][j]=='O');
    }
    for(int i=0;i<(1<<10);i++)
    {
        for(int j=0;j<10;j++)
            for(int k=0;k<10;k++)
                brr[j][k]=arr[j][k];
        cnt=0;
        for(int j=0;j<10;j++)
        {
            if(i&(1<<j))
                push(0,j);
        }
        for(int j=1;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                if(brr[j-1][k])
                    push(j,k);
            }
        }
        int flag=0;
        for(int j=0;j<10;j++)
            flag|=brr[9][j];
        if(flag==0)
            mn=min(mn,cnt);
    }
    if(mn==(int)1e9) cout<<-1;
    else cout<<mn;
}