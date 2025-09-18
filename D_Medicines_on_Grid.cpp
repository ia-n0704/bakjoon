# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m;
string s[1000];
int q;
int ch[1000][1000];
int arr[1000][1000];
pair<int,int> st,en;
int flag;
int X[5]={-1,0,1,0};
int Y[5]={0,1,0,-1};
int mx[1000][1000];
int check[1000][1000];
void ch_dfs(int x,int y)
{
    if(flag) return;
    //cout<<x<<" "<<y<<" "<<e<<'\n';
    if(x<0 || x>=n || y<0 || y>=m)
        return;
    if(x==en.first && y==en.second)
    {
        flag=1;
        return;
    }
    check[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int nx=x+X[i];
        int ny=y+Y[i];
        if(nx<0 || nx>=n || ny<0 || ny>=m)
            continue;
        if(ch[nx][ny]==1 && check[nx][ny]==0)
        {
            check[nx][ny]=1;
            ch_dfs(nx,ny);
        }
    }
}
void dfs(int x,int y,int e)
{
    if(flag) return;
    //cout<<x<<" "<<y<<" "<<e<<'\n';
    if(x<0 || x>=n || y<0 || y>=m)
        return;
    if(x==en.first && y==en.second)
    {
        flag=1;
        return;
    }
    if(e<=0)
        return;
    mx[x][y]=e;
    //if(abs(en.first-x)+abs(en.second-y)>e) return;
    for(int i=0;i<4;i++)
    {
        int nx=x+X[i];
        int ny=y+Y[i];
        if(nx<0 || nx>=n || ny<0 || ny>=m)
            continue;
        if(ch[nx][ny]==1 && mx[nx][ny]<e-1)
        {
            if(e<arr[nx][ny])
                e=arr[nx][ny]+1;
            int temp=arr[nx][ny];
            arr[nx][ny]=0;
            dfs(nx,ny,e-1);
            arr[nx][ny]=temp;
        }
    }
}
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>s[i];
    cin>>q;
    while(q--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        arr[a-1][b-1]+=c;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            mx[i][j]=-1;
            if(s[i][j]!='#')
                ch[i][j]=1;
            if(s[i][j]=='S')
                st={i,j};
            if(s[i][j]=='T')
                en={i,j};
        }
    }
    ch_dfs(st.first,st.second);
    if(flag==0)
    {
        cout<<"No";
        return 0;
    }
    flag=0;
    int temp=arr[st.first][st.second];
    arr[st.first][st.second]=0;
    mx[st.first][st.second]=temp;
    dfs(st.first,st.second,temp);
    if(flag) cout<<"Yes";
    else cout<<"No";
}