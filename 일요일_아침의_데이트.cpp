# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
struct T
{
    int cnt1,cnt2,x,y;
};
struct compare
{
    bool operator()(T a,T b){
        if(a.cnt1==b.cnt1) return a.cnt2>b.cnt2;
        return a.cnt1>b.cnt1;
    }
};
const ll inf=1e9;
string s[100];
pair<int,int> ch[100][100];
int arr[100][100];
int enx,eny,stx,sty;
int X[5]={-1,0,1,0};
int Y[5]={0,1,0,-1};
int n,m;
int cnt=0;
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        for(int j=0;j<m;j++)
        {
            ch[i][j]={inf,inf};
            if(s[i][j]=='g') arr[i][j]=1;
            else if(s[i][j]=='S')
            {
                arr[i][j]=2;
                stx=i;
                sty=j;
            }
            else if(s[i][j]=='F')
            {
                arr[i][j]=2;
                enx=i;
                eny=j;
            }
        }
    }
    priority_queue<T,vector<T>,compare> pq;
    pq.push({0,0,stx,sty});
    while(!pq.empty())
    {
        auto a=pq.top();
        pq.pop();
        if((a.cnt1==ch[a.x][a.y].first && a.cnt2<ch[a.x][a.y].second) || a.cnt1<ch[a.x][a.y].first)
            ch[a.x][a.y]={a.cnt1,a.cnt2};
        else continue;
        for(int i=0;i<4;i++)
        {
            int nx=a.x+X[i];
            int ny=a.y+Y[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            pair<int,int> b={a.cnt1,a.cnt2};
            if(arr[nx][ny]==1) b={a.cnt1+1,a.cnt2};
            else if(!arr[nx][ny])
            {
                for(int j=0;j<4;j++)
                {
                    int nnx=nx+X[j];
                    int nny=ny+Y[j];
                    if(nnx<0 || nnx>=n || nny<0 || nny>=m) continue;
                    if(arr[nnx][nny]==1)
                    {
                        b.second++;
                        break;
                    }
                }
            }
            if((b.first==ch[nx][ny].first && b.second<ch[nx][ny].second) || b.first<ch[nx][ny].first)
                pq.push({b.first,b.second,nx,ny});
        }
    }
    cout<<ch[enx][eny].first<<' '<<ch[enx][eny].second;
}