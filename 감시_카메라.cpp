# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroint-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,k;
int mx[2000010][23];
int main()
{
    fastio;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a<=b)
        {
            mx[a][0]=max(mx[a][0],b);
            mx[n+a][0]=max(mx[n+a][0],n+b);
        }
        else
            mx[a][0]=max(mx[a][0],n+b);
    }
    for(int i=1;i<=2*n;i++)
    {
        mx[i][0]=max(mx[i-1][0],mx[i][0]);
        if(mx[i][0]<i) mx[i][0]=-1;
        //cout<<i<<" : "<<mx[i][0]<<"\n";
    }
    for(int i=1;i<=22;i++)
    {
        for(int j=1;j<=2*n;j++)
        {
            if(mx[j][i-1]+1>=n+j) mx[j][i]=-1;
            else if(mx[j][i-1]==-1) mx[j][i]=-1;
            else mx[j][i]=mx[mx[j][i-1]+1][i-1];
            if(mx[j][i]>=n+j) mx[j][i]=-1;
        }
    }
    int ans=(int)1e9;
    for(int i=1;i<=n*2;i++)
    {
        int cur=i;
        int res=0;
        for(int j=22;j>=0;j--)
        {
            //cout<<cur<<" ";
            if(mx[cur][j]!=-1 && (j==0 || mx[cur][j]<=n+i))
            {
                cur=mx[cur][j]+1;
                //cout<<" | "<<j<<"\n";
                res+=(1<<j);
            }
            //cout<<cur<<'\n';
            if(cur>=n+i) break;
        }
        if(cur>=n+i) ans=min(ans,res);
        //cout<<ans<<" "<<res<<'\n';
    }
    if(ans==(int)1e9) cout<<"impossible";
    else cout<<ans;
}