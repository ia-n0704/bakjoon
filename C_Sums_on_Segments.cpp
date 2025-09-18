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
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<ll> vll;
ll n;
ll arr[200010];
void sol()
{
    cin>>n;
    ll idx=1;
    for(ll i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]!=-1 && arr[i]!=1)
            idx=i;
    }

    ll a=0,b=0;
    ll mn=0;
    ll sum=0;
    ll mx=0;
    for(ll i=1;i<idx;i++)
    {
        sum+=arr[i];
        mn=min(mn,sum);
        a=max(a,sum-mn);
    }
    sum=0;
    for(ll i=1;i<idx;i++)
    {
        sum+=arr[i];
        mx=max(mx,sum);
        b=min(b,sum-mx);
    }
    vector<ll> v;
    for(ll i=b;i<=a;i++)
        v.push_back(i);
    sum=0;
    a=0;
    b=0;
    mn=0;
    mx=0;
    for(ll i=idx+1;i<=n;i++)
    {
        sum+=arr[i];
        mn=min(mn,sum);
        a=max(a,sum-mn);
    }
    sum=0,mx=0;
    for(ll i=idx+1;i<=n;i++)
    {
        sum+=arr[i];
        mx=max(mx,sum);
        b=min(b,sum-mx);
    }
    //cout<<a<<" "<<b<<'\n';
    for(ll i=b;i<=a;i++)
        v.push_back(i);
    
    mn=mx=0;
    sum=0;
    for(ll i=idx-1;i>=1;i--)
    {
        sum+=arr[i];
        mn=min(mn,sum);
        mx=max(mx,sum);
    }
    for(ll i=mn;i<=mx;i++)
        v.push_back(i+arr[idx]);
    ll mn1=mn,mx1=mx;
    mn=mx=0;
    sum=0;
    for(ll i=idx+1;i<=n;i++)
    {
        sum+=arr[i];
        mn=min(mn,sum);
        mx=max(mx,sum);
    }
    mn+=mn1;
    mx+=mx1;
    for(ll i=mn;i<=mx;i++)
        v.push_back(i+arr[idx]);
    sort(all(v));
    v.erase(unique(all(v)),v.end());
    cout<<v.size()<<'\n';
    for(auto i:v) cout<<i<<" ";
    cout<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}