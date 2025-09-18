# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s[5];
int arr[5][100010];
void sol()
{
    cin>>n;
    cin>>s[1];
    cin>>s[2];
    for(int i=1;i<=2;i++)
        for(int j=0;j<n;j++)
            arr[i][j+1]=s[i][j]=='A'?1:0;
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(ch[i][j]) continue;
            int nx,ny,nnx,nny;
            if(j%2)
            {
                if(i==1)
                {
                    nx=i+1;
                    ny=j;
                    nnx=i+1;
                    nny=j+1;
                    go();
                    nnx=i;
                    nny=j+1;
                    go();                    
                }
                else
                {
                    
                }
            }
        }
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}