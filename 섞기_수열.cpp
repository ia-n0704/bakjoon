# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
int ch[20010];
int arr[20010];
ll gcd(ll a,ll b)
{
    while(b)
    {
        ll temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
ll lcm(ll a,ll b)
{
    return a*b/gcd(a,b);
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    ll ans=1;
    for(int i=1;i<=n;i++)
    {
        if(ch[i]) continue;
        ll cnt=1;
        ll temp=arr[i];
        while(temp!=i)
        {
            ch[temp]=1;
            temp=arr[temp];
            cnt++;
        }
        ans=lcm(ans,cnt);
    }
    cout<<ans;
}