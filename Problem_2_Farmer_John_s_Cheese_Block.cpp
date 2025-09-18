# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,q;
int ch1[1010][1010],ch2[1010][1010],ch3[1010][1010];
int main()
{
    fastio;
    cin>>n>>q;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            ch1[i][j]=ch2[i][j]=ch3[i][j]=n;
    }
    int cnt=0;
    for(int i=0;i<q;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        ch1[x][y]--;
        if(ch1[x][y]==0) cnt++;
        ch2[x][z]--;
        if(ch2[x][z]==0) cnt++;
        ch3[y][z]--;
        if(ch3[y][z]==0) cnt++;
        cout<<cnt<<'\n';
    }
}