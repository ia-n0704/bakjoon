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
string str[100];
int arr[25][25][25][25];
int check(int x,int y)
{
    return x<0 || x>=n || y<0 || y>=m;
}
int G(int a,int b,int l,int r)
{
    if(check(a,b) || check(l,r) || a>l || b>r) return 0;
    if(arr[a][b][l][r]!=-1) return arr[a][b][l][r];
    int ch[105];
    fill(ch,ch+101,0);
    for(int i=a;i<=l;i++)
    {
        for(int j=b;j<=r;j++)
        {
            if(str[i][j]=='X')
                continue;
            int num=0;
            num^=G(a,b,i-1,j-1);
            num^=G(i+1,j+1,l,r);
            num^=G(a,j+1,i-1,r);
            num^=G(i+1,b,l,j-1);
            ch[num]=1;
        }
    }
    for(int i=0;i<100;i++)
    {
        if(!ch[i])
            return arr[a][b][l][r]=i;
    }
    return 0;
}
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>str[i];
    memset(arr,-1,sizeof(arr));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(str[i][j]=='.')
                arr[i][j][i][j]=1;
        }
    }
    if(G(0,0,n-1,m-1))
        cout<<"First";
    else cout<<"Second";
}