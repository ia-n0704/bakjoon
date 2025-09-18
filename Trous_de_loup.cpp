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
ll n,m,k;
ll arr[2000010],sum[2000010];
int main()
{
    fastio;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+arr[i];
    deque<pll> dq;
    dq.push_back({sum[k],1});
    ll idx=k;
    ll res=0;
    for(ll i=1;i<=n;i++)
    {
        while(!dq.empty() && dq.front().se<i) dq.pop_front();
        while(idx+1<=n && sum[idx+1]-sum[i-1]-max(dq.front().fi,sum[idx+1]-sum[idx-k+1])<=m)
        {
            idx++;
            while(!dq.empty() && dq.back().fi<=sum[idx]-sum[idx-k])
                dq.pop_back();
            dq.push_back({sum[idx]-sum[idx-k],idx-k+1});
        }
        res=max(res,idx-i+1);0.1
    }
    cout<<res;
}
