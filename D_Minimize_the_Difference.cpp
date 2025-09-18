# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll arr[200010],brr[200010];
void sol()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    ll l=1,r=arr[1];
    while(l<=r)
    {
        ll mid=(l+r)/2;
        int flag=0;
        ll num=0;
        for(int i=1;i<=n;i++)
        {
            if(arr[i]+num<mid)
            {
                flag=1;
                break;
            }
            num=arr[i]+num-mid;
        }
        if(flag) r=mid-1;
        else l=mid+1;
    }
    ll mn=r;
    l=mn,r=1e18;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        ll num=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i]<mid)
                num=max(0ll,num-mid+arr[i]);
            else
                num+=max(0ll,arr[i]-mid);
        }
        if(num+arr[n]<=mid) r=mid-1;
        else l=mid+1;
    }
    ll mx=l;
    cout<<mx-mn<<'\n';
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