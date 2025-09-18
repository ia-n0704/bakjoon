# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[200010];
void sol()
{
    ll n,k;
    ll res=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+n+1);
    ll l=1,r=1e12;
    while(l<=r)
    {
        ll num=0;
        ll mid=(l+r)/2;
        for(int i=1;i<=n;i++)
            num+=max(0ll,mid-arr[i]);
        //cout<<num<<'\n';
        if(num>k)
            r=mid-1;
        else
        {
            res=mid;
            l=mid+1;
        }
    }
    ll temp=k;
    for(int i=1;i<=n;i++)
    {
        if(res<=arr[i]) continue;
        //cout<<temp<<" "<<res<<" "<<arr[i]<<'\n';
        temp-=(res-arr[i]);
        arr[i]=res;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==res) cnt++;
    }
    cout<<n*res-(cnt-1-temp)<<'\n';
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