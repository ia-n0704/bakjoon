# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int num[15010][1510];
string s[15010];
int n,m;
int res;
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(int j=1;j<=m;j++)
            num[i][j]=s[i][j-1]-'0';
    }
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(num[i][j]==0) continue;
            if(num[i-1][j])
                num[i][j]=num[i-1][j]+1;
            else num[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        sort(num[i]+1,num[i]+m+1);
        reverse(num[i]+1,num[i]+m+1);
        for(int j=1;j<=m;j++)
            res=max(res,j*num[i][j]);
    }  
    cout<<res;
}