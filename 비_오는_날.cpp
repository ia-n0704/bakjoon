# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n;
ll arr[300010];
priority_queue<pair<pair<ll,ll>,ll>,vector<pair<pair<ll,ll>,ll>>,greater<pair<pair<ll,ll>,ll>>> pq;
int main()
{
    fastio;
    ll res=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        res+=arr[i];
        pq.push({{3*arr[i],3},i});
    }
    for(int i=1;i<=n-2;i++)
    {
        auto a=pq.top();
        pq.pop();
        res+=a.first.first;
        pq.push({{(a.first.second+2)*arr[a.second],a.first.second+2},a.second});
    }
    if(n==1) cout<<0;
    else cout<<res;
}