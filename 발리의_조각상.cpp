/*# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,l,r;
int arr[2010];
const int mx=1e9;
struct Billy
{
    int a,b,ab;
}dp[2010][2010];
int main()
{
    fastio;
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++) cin>>arr[i];
    dp[1][0].a=0;
    dp[1][0].b=arr[1];
    dp[1][0].ab=arr[1];
    for(int i=1;i<=r;i++)
        dp[1][i].a=dp[1][i].b=dp[1][i].ab=mx;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=r;j++)
        {
            Billy resa,resb;
            if(j==0) resa.a=resa.b=mx;
            else
            {
                resa.a=dp[i-1][j-1].ab;
                resa.b=arr[i];
            }
            resa.ab=resa.a|resa.b;

            resb.a=dp[i-1][j].a;
            resb.b=dp[i-1][j].b+arr[i];
            resb.ab=resb.a|resb.b;
            if(resa.ab<=resb.ab)
                dp[i][j]=resa;
            else dp[i][j]=resb;
            //cout<<dp[i][j].ab<<" ";
        }
        //cout<<'\n';
    }
    cout<<dp[n][r].ab;
}*/


# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,l,r;
ll dp1[2010],dp2[2010][2010];
ll sum[2010];
ll arr[2010];
ll num[2010];
int main()
{
    fastio;
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+arr[i];
    fill(num,num+63,1);
    for(int i=60;i>=0;i--)
    {
        ll temp=0;
        num[i]=0;
        for(int i=0;i<=60;i++) temp+=num[i]*(1ll<<i);
        int flag=0;
        if(l==1)
        {
            dp1[0]=0;
            for(int j=1;j<=n;j++)
            {
                dp1[j]=(ll)1e16;
                for(int k=0;k<j;k++)
                    if(((sum[j]-sum[k])|temp)==temp) dp1[j]=min(dp1[j],dp1[k]+1);
            }if(dp1[n]<=r) flag=1;
        }
        else
        {
            dp2[0][0]=1;
            for(int j=1;j<=n;j++)
            {
                dp2[j][0]=0;
                dp2[0][min(r,(ll)j)]=0;
            }
            for(int j=1;j<=n;j++)
            {
                for(int k=1;k<=r;k++)
                {
                    dp2[j][k]=0;
                    for(int l=0;l<j;l++)
                    {
                        if(dp2[l][k-1] && ((sum[j]-sum[l]|temp)==temp))
                        {
                            dp2[j][k]=1;
                            break;
                        }
                    }
                }
            }
            for(int j=l;j<=r;j++)
            {
                if(dp2[n][j])
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0) num[i]=1;
    }
    ll res=0;
    for(int i=0;i<=60;i++)
        res+=num[i]*(1ll<<i);
    cout<<res;
}