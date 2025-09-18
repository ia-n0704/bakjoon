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
ll arr[1000010];
int main()
{
    fastio;
    cin>>n;
    ll res=0;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    priority_queue<ll> pq;
    for(int i=1;i<=n;i++)
    {
        pq.push(arr[i]-i+1);
        if(!pq.empty() && pq.top()>arr[i]-i+1)
        {
            res+=pq.top()-arr[i]+i-1;
            pq.pop();
        }
    }
    cout<<res;
}