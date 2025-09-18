# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010],b[200010];
void sol()
{
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    ll res=0;
    for(int i=m+1;i<=n;i++)
        res+=min(a[i],b[i]);
    ll ans=1e16;
    for(int i=m;i>=1;i--)
    {
        ans=min(ans,res+a[i]);
        res+=min(a[i],b[i]);
    }
    cout<<ans<<'\n';
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