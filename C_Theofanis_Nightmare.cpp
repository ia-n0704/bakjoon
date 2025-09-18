# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100010],sum[100010];
void sol()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+arr[i];
    ll res=0;
    ll num=0;
    int idx=1;
    for(int i=1;i<=n;i++)
    {
        num+=arr[i];
        if(sum[n]-sum[i]>=0)
        {
            
            res+=idx*num;
            num=0;
            idx++;
        }
    }
    cout<<res<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}