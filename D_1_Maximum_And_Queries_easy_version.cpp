# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100010];
void sol()
{
    int n;
    cin>>n;
    int q;
    cin>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+n+1);
    while(q--)
    {
        ll k;
        cin>>k;
        ll l=arr[1],r=arr[n];
        ll res=0;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            ll num=0;
            for(int i=1;i<=n;i++)
                num+=max(0ll,arr[i]-mid);
            if(num>k) r=mid-1;
            else 
            {
                res=mid;
                l=mid+1;
            }
        }
        cout<<res<<'\n';
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    sol();
}