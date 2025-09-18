# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int h,w,n;
string t;
string str[1000];
int flag;
void dfs(int x,int y,int num)
{
    if(x<0 || y<0 || x>=h || y>=w || str[x][y]=='#')
    {
        flag=0;
        return;
    }
    if(num>=n)
    {
        flag=1;
        return;
    }
    if(t[num]=='L')
    {
        dfs(x,y-1,num+1);
    }
    else if(t[num]=='R')
    {
        dfs(x,y+1,num+1);
    }
    else if(t[num]=='U')
    {
        dfs(x-1,y,num+1);
    }
    else if(t[num]=='D')
    {
        dfs(x+1,y,num+1);
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>h>>w>>n;
    cin>>t;
    for(int i=0;i<h;i++) cin>>str[i];
    int cnt=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            flag=0;
            dfs(i,j,0);
            if(flag)
                cnt++;
        }
    }
    cout<<cnt;
}