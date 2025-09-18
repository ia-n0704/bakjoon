# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin,(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
pair<ll,ll> arr[100010];
ll res;
ll f(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c)
{
    return (a.fi*b.se+b.fi*c.se+c.fi*a.se)-(a.se*b.fi+b.se*c.fi+c.se*a.fi);
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].fi>>arr[i].se;
        if(i>=3)
            res+=f(arr[1],arr[i-1],arr[i]);
    }
    res=abs(res);
    cout<<res/2;
    if(res%2) cout<<".5";
    else cout<<".0";
}
