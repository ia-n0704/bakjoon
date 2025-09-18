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
ll arr[200010];
int main()
{
    fastio;
    cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    ll l=0,r=1000000000;
    ll res=0;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        ll temp=arr[0];
        ll cnt=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]-temp>=mid)
            {
                temp=arr[i];
                cnt++;
            }
        }
        //cout<<mid<<" "<<cnt<<'\n';
        if(cnt>=q)
        {
            res=max(res,mid);
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<res;
}