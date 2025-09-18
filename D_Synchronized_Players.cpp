# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int n;
string s[100];
int res=1000000000;
int ch[100][100][100][100];
int x[5]={-1,0,1,0},y[5]={0,1,0,-1};
void bfs(int x1,int y1,int x2,int y2,int cnt)
{
    //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<cnt<<'\n';
    if(ch[x1][y1][x2][y2]<=cnt)
        return;    
    if(x1==x2 && y1==y2)
    {
        res=min(res,cnt);
        return;
    }
    ch[x1][y1][x2][y2]=cnt;
    for(int i=0;i<4;i++)
    {
        int a=x1+x[i],b=y1+y[i];
        int c=x2+x[i],d=y2+y[i];
        if(a<0 || a>=n || b<0 || b>=n)
        {
            a=x1;
            b=y1;
        }
        else if(s[a][b]=='#')
        {
            a=x1;
            b=y1;
        }
        if(c<0 || c>=n || d<0 || d>=n)
        {
            c=x2;
            d=y2;
        }
        else if(s[c][d]=='#')
        {
            c=x2;
            d=y2;
        }
        bfs(a,b,c,d,cnt+1);
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>s[i][j];
            if(s[i][j]=='P')
                v.push_back({i,j});
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)    
            for(int r=0;r<n;r++)
                for(int k=0;k<n;k++)
                    ch[i][j][r][k]=1000000000;
    bfs(v[0].first,v[0].second,v[1].first,v[1].second,0);
    if(res==1000000000) cout<<-1;
    else cout<<res;
}