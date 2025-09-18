# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int arr[1510][1510];
int num[1510][1510];
int n,m;
int res;
int main()
{
    fastio;
    while(1)
    {
        cin>>n>>m;
        if(!n && !m) break;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                cin>>arr[i][j];
        }
        for(int j=1;j<=m;j++)
        {
            for(int i=1;i<=n;i++)
            {
                if(arr[i][j]==0) continue;
                else num[i][j]=num[i-1][j]+1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            sort(num[i]+1,num[i]+m+1);
            reverse(num[i]+1,num[i]+m+1);
        }
        for(int j=1;j<=m;j++)
        {
            int mx=0;
            for(int i=1;i<=n;i++)
                mx=max(mx,num[i][j]);
            res=max(res,mx*j);
        }  
        cout<<res<<'\n';   
        res=0;     
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++) num[i][j]=0;
    }
}