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
ll n,l,r;
ll arr[100010];
void sol()
{
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++) cin>>arr[i];
    vector<int> v;
    for(int i=1;i<=r;i++)
        v.push_back(arr[i]);
    sort(all(v));
    ll sum=0;
    for(int i=1;i<=r-l+1;i++)
        sum+=v[i-1];
    ll res=sum;
    v.clear();
    for(int i=l;i<=n;i++)
    {
        v.push_back(arr[i]);
    }
    sort(all(v));
    sum=0;
    for(int i=1;i<=r-l+1;i++)
        sum+=v[i-1];
    res=min(res,sum);
    cout<<res<<'\n';
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