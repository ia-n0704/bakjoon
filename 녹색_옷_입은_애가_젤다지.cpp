# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll inf=1e16;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
int arr[200][200];
int ch[200][200];
int X[5]={-1,0,1,0};
int Y[5]={0,1,0,-1};
void go(int x,int y,int co)
{
    if(x==n && y==n)
        return;
    for(int i=0;i<4;i++)
    {
        int nx=x+X[i];
        int ny=y+Y[i];
        if(nx<1 || ny<1 || nx>n || ny>n) continue;
        int nco=co+arr[nx][ny];
        if(nco>=ch[nx][ny]) continue;
        ch[nx][ny]=nco;
        go(nx,ny,nco);
    }
}
int main()
{
    fastio;
    int idx=1;
    while(1)
    {
        cin>>n;
        if(n==0) break;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                ch[i][j]=inf;
                cin>>arr[i][j]; 
            }       
        }
        //go(1,1,arr[1][1]);
        queue<pair<int,int>> q;
        q.push({1,1});
        ch[1][1]=arr[1][1];
        while(!q.empty())
        {
            auto a=q.front();
            q.pop();
            int x=a.first;
            int y=a.second;
            for(int i=0;i<4;i++)
            {
                int nx=x+X[i];
                int ny=y+Y[i];
                if(nx<1 || ny<1 || nx>n || ny>n)
                    continue;
                if(ch[nx][ny]<=ch[x][y]+arr[nx][ny])
                    continue;
                ch[nx][ny]=ch[x][y]+arr[nx][ny];
                q.push({nx,ny});
            }
        }
        cout<<"Problem "<<idx++<<": "<<ch[n][n]<<'\n';
    }
}