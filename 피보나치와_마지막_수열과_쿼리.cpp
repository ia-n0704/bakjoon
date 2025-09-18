# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,q;
const ll mod=1e9+7;
pair<ll,ll> arr[1000010];
ll par[1000010];
ll fibo[1000010];
ll ans[1000010];
int main()
{
    fastio;
    fibo[0]=fibo[1]=1;
    for(int i=2;i<=1000000;i++)
        fibo[i]=(fibo[i-2]+fibo[i-1])%mod;
    cin>>n>>q;
    for(int i=q-1;i>=0;i--)
        cin>>arr[i].first>>arr[i].second;
    for(int i=0;i<q;i++)
    {
        int idx=1;
        for(int j=arr[i].first;j<=arr[i].second;j++)
        {
            if(par[j]>=j) 
            {
                idx+=par[j]-j+1;
                j=par[j];
            }
            else
            {
                ans[j]=fibo[idx++];
                par[j]=arr[i].second;
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
}