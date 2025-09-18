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
int v[3010][3010];
int ch[3010];
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a][b]=1;
        v[b][a]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(ch[i]) continue;
        for(int j=i+1;j<=n;j++)
        {
            if(v[i][j]==0 && ch[j]==0)
            {
                ch[j]=1;
                ch[i]=1;
                break;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(cnt==n/3) break;
        if(ch[i]==0)
        {
            cout<<i<<" ";
            cnt++;
        }
    }
}