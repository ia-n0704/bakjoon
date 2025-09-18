# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define z first.first
#define x first.second
#define y second
int X[7]={-1,0,1,0,0,0};
int Y[7]={0,1,0,-1,0,0};
int Z[7]={0,0,0,0,-1,1};
int arr[110][110][110];
queue<pair<pair<int,int>,int>> q;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    for(int r=0;r<k;r++)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>arr[r][i][j];
                if(arr[r][i][j]==1)
                    q.push({{r,i},j});
            }
        }
    }
    int cnt=0;
    while(!q.empty())
    {
        cnt++;
        //printf("%d\n",q.size());
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            pair<pair<int,int>,int> a=q.front();
            //cout<<a.z<<" "<<a.x<<" "<<a.y<<'\n';
            //printf("%d %d\n",q,sizei);
            q.pop();
            for(int j=0;j<6;j++)
            {
                int nx=a.x+X[j];
                int ny=a.y+Y[j];
                int nz=a.z+Z[j];
                if(nz>=0 && nz<k && nx>=0 && nx<m && ny>=0 && ny<n && arr[nz][nx][ny]==0)
                {
                    //printf("%d\n",a.z);
                    q.push({{nz,nx},ny});
                    arr[nz][nx][ny]=1;
                }
            }
        }

    }
    int flag=0;
    for(int r=0;r<k;r++)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                if(arr[r][i][j]==0) flag=1;
        }
    }

    if(flag) printf("-1");
    else printf("%d",cnt-1);
}