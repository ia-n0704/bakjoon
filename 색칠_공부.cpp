# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
const ll mod=1e9+7;
ll n,k;
int f[1000010];
int ch[1000010];
ll dp[1000010];
int cnt;
int main()
{
    fastio;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>f[i];
    dp[0]=k;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]*(k-2)+dp[i-2]*(k-1);
        dp[i]%=mod;
    }
    ll ans=1;
    ll cnt=n;
    int num=1;
    for(int i=1;i<=n;i++)
    {
        if(ch[i])
            continue;
        int a=i;
        while(ch[a]==0)
        {
            ch[a]=num;
            a=f[a];
            num++;
        }
        //cout<<a<<" "<<ch[a]<<" "<<ch[i]<<'\n';
        if(ch[a]>=ch[i])
        {
            if(num-ch[a]==1) ans*=k;
            else ans*=dp[num-ch[a]];
            ans%=mod;
            cnt-=(num-ch[a]);            
        }
    }
    //cout<<ans<<'\n';
    for(int i=1;i<=cnt;i++)
    {
        ans*=k-1;
        ans%=mod;
    }
    cout<<ans;
}