# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int t,n,m;
int arr[20010],brr[20010];
int main()
{
    fastio;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>arr[i];
        for(int i=1;i<=m;i++) cin>>brr[i];
        sort(brr+1,brr+m+1);
        ll res=0;
        for(int i=1;i<=n;i++)
            res+=(lower_bound(brr+1,brr+m+1,arr[i])-brr)-1;
        cout<<res<<'\n';
    }
}