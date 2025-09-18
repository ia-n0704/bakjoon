#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int sum[510][510];
int ch[510][510];
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin>>sum[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(ch[i][j]) continue;
            int flag=0;
            for(int x=1;x+i-1<=n;x++)
            {
                for(int y=1;y+j-1<=m;y++)
                {
                    int tx=x+i-1;
                    int ty=y+j-1;
                    if((sum[tx][ty]-sum[x-1][ty]-sum[tx][y-1]+sum[x-1][y-1])%k!=0)
                        flag=1;
                }
            }
            if(!flag)
            {
                for(int ii=i;ii<=n;ii+=i)
                {
                    for(int jj=j;jj<=m;jj+=j)
                    {
                        if(ch[ii][jj]) continue;
                        ch[ii][jj]=1;
                        cnt++;
                    }
                }
            }
        }
    }
    if(cnt==0)
    {
        cout<<-1;
        return 0;
    }
    cout<<cnt<<'\n';
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(ch[i][j]) cout<<i<<" "<<j<<'\n';
}