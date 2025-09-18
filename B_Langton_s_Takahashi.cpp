# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int ch[101][101];
int h,w,n;
int x[5]={-1,0,1,0},y[5]={0,1,0,-1};
void bfs(int a,int b,int d,int cnt)
{
    if(cnt>=n)
        return;
    if(a<1) a=h;
    if(a>h) a=1;
    if(b<1) b=w;
    if(b>w) b=1;
    if(ch[a][b]==0)
    {
        ch[a][b]=1;
        d++;
        d%=4;
    }
    else
    {
        ch[a][b]=0;
        d--;
        if(d<0) d+=4;
    }
    bfs(a+x[d],b+y[d],d,cnt+1);
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>h>>w>>n;
    bfs(1,1,0,0);
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(ch[i][j]==0) cout<<".";
            else cout<<"#";
        }
        cout<<'\n';
    }
}