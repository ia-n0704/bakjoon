# pragma GCC optimize ("O3")

# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,m;
const ll num=1<<21;
struct T
{
    ll a,b,c;
};
T arr[30];
ll H[num],W[num],dp[num];
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>arr[i].a>>arr[i].b>>arr[i].c;
    for(int i=0;i<=(1<<n);i++) dp[i]=-1;
    dp[0]=(ll)1e16;
    ll res=-1;
    for(int i=1;i<=(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                H[i]=H[i^(1<<j)]+arr[j+1].a;
                W[i]=W[i^(1<<j)]+arr[j+1].b;
                ll temp1=min(arr[j+1].c,dp[i^(1<<j)]-arr[j+1].b);
                ll temp2=min(dp[i^(1<<j)],arr[j+1].c-W[i^(1<<j)]);
                dp[i]=max(dp[i],max(temp1,temp2));
            }
        }
        if(H[i]>=m)
            res=max(res,dp[i]);
    }
    if(res==-1) cout<<"Mark is too tall";
    else cout<<res;
}