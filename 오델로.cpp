# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
string s[550];
int X[10]={-1,-1,-1,0,1,1,1,0};
int Y[10]={-1,0,1,1,1,0,-1,-1};
int ch[10];
int main()
{
    fastio;
    cin>>n;
    for(int i=0;i<n;i++) cin>>s[i];
    int mx=0,mxi,mxj;
    for(int i=0;i<n;i++)
    {
        int temp=0;
        fill(ch,ch+9,0);
        for(int j=0;j<n;j++)
        {
            if(s[i][j]!='.') continue;
            for(int r=0;r<8;r++)
            {
                int flag=0;
                int nx=i+X[r];
                int ny=j+Y[r];
                int cnt=0;
                while(1)
                {
                    if(nx<0 || ny<0 || nx>=n || ny>=n)
                    {
                        flag=1;
                        break;
                    }
                    if(s[nx][ny]=='B')
                        break;
                    if(s[nx][ny]=='W') cnt++;
                    nx+=X[r];
                    ny+=Y[r];
                }
                if(!flag) temp+=cnt;
            }
            if(mx<temp)
            {
                mxi=i;
                mxj=j;
                mx=temp;
            }
        }
    }
    if(mx==0)
        cout<<"PASS";
    else cout<<mxj<<" "<<mxi<<'\n'<<mx;
}