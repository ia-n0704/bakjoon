# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
void sol()
{
    int n;
    ll res=1;
    cin>>n;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(int i=1;i<=n;i++)
    {
        ll a;
        cin>>a;
        pq.push(a);
    }
    while(pq.size()>1)
    {
        ll a=pq.top();
        pq.pop();
        ll b=pq.top();
        pq.pop();
        res*=(a*b)%mod;
        res%=mod;
        pq.push(a*b);
    }
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