# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,m;
ll arr[1000010];
vector<pll> v;
ll LIS(vector<ll> t)
{
    vector<ll> lis;
    lis.push_back(t[0]);
    for(ll i=1;i<t.size();i++)
    {
        ll idx=upper_bound(lis.begin(),lis.end(),t[i])-lis.begin();
        if(idx>=lis.size()) lis.push_back(t[i]);
        else lis[idx]=t[i];
    }
    return lis.size();
}
int main()
{
    fastio;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>arr[i];
        v.push_back({arr[i]+i*m,-arr[i]+i*m});
    }
    stable_sort(v.begin(),v.end());
    vector<ll> v2;
    for(auto i:v)
        v2.push_back(i.second);
    cout<<n-LIS(v2);
}