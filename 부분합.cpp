# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,k;
ll arr[100010];
ll s[100010];
int main()
{
    fastio;
    cin>>n>>k;
    for(int i=1;i<=n;i++) 
    {
        cin>>arr[i];
        s[i]=s[i-1]+arr[i];
    }
    int l=1,r=1;
    int res=100010;
    while(l<=n && r<=n)
    {
        while(r<=n && s[r]-s[l-1]<k) r++;
        if(r>n) break;
        res=min(res,r-l+1);
        l++;
    }
    if(res==100010) cout<<0;
    else
        cout<<res;
}