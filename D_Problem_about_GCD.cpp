# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
ll l,r,n;
void sol()
{
    cin>>l>>r>>n;
    ll s=l+n-l%n;
    if(l%n==0) s-=n;
    ll e=r+n-r%n;
    e-=n;
    if(s>e)
    {
        cout<<"-1 -1\n";
        return;
    }
    pll temp={s,e};
    while(s<=e && __gcd(s,e)!=n)
        e-=n;
    pair<ll,pll> num={e-s,{s,e}};
    s=temp.fi;
    e=temp.se;
    while(s<=e && __gcd(s,e)!=n)
        s+=n;
    if(num.fi>=e-s)
    {
        s=num.se.fi;
        e=num.se.se;
    }
    if(s>e)
    {
        cout<<"-1 -1\n";
        return;
    }
    cout<<s<<" "<<e<<'\n';
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