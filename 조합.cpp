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
ll arr[50010];
int ch[5010];
ll res=0;
ll fact[5010],inverse[5010];
const ll mod=1e9+9;
ll power(ll x, ll y) {
    if (y == 0) return 1;
    if (y % 2 == 1) return (power(x, y - 1) * x) % mod;
    ll half = power(x, y / 2) % mod;
    return half * half % mod;
}
ll P(int a,int b)
{
    return (((fact[a]*inverse[a-b])%mod)*inverse[b])%mod;
}
int main()
{
    fastio;
    fact[0]=1;
    for(int i=1;i<=5000;i++) fact[i]=fact[i-1]*i%mod;
    inverse[5000] = power(fact[5000], mod - 2);
    for (int i = 5000 - 1; 0 <= i; i--)
        inverse[i] = inverse[i + 1] * (i + 1) % mod;
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>arr[i];
    for(int i=1;i<=m;i++)
    {
        for(int j=arr[i-1]+1;j<arr[i];j++)
        {
            res+=P(n-j,m-i);
            res%=mod;            
        }
        ch[arr[i]]=1;
        //cout<<res<<" ";
    }
    cout<<(res+1)%mod<<'\n';
    int i,flag;
    for(i=m;i>=1;i--)
    {
        flag=0;
        for(int j=arr[i]+1;j<=n;j++)
        {
            if(ch[j]==0)
            {
                flag=j;
                break;
            }
        }
        if(flag)
            break;
    }
    for(int j=m;j>i;j--) ch[arr[j]]=0;
    for(int j=1;j<i;j++) cout<<arr[j]<<" ";
    cout<<flag<<" ";
    m-=i;
    for(int j=flag+1;j<=n;j++)
    {
        if(m==0) break;
        if(ch[j]==0)
        {
            cout<<j<<" ";
            m--;
        }
    }
}
