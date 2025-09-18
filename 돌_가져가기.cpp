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
string s;
priority_queue<ll> pq;
ll arr[300010];
int main()
{
    fastio;
    cin>>n>>s;
    ll mx=0;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i==0) continue;
        if(flag && s[i]!=s[i-1])
        {
            pq.push(mx);
            mx=0;
        }
        if(!flag && s[i]!=s[i-1])
        {
            mx=0;
            flag=1;
        }           
        mx=max(mx,arr[i]);
    }
    ll res=0;
    n=pq.size();
    for(int i=1;i<=(n+1)/2;i++)
    {
        res+=pq.top();
        pq.pop();
    }
    cout<<res;
}