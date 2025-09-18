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
ll arr[300010];
ll a[300010];
ll b[300010];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    stack<pair<int,int>> mx,mn;
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        while(!mx.empty())
        {
            if(mx.top().first<arr[i]) mx.pop();
            else break;
        } 
        while(!mn.empty())
        {
            if(mn.top().first>arr[i]) mn.pop();
            else break;
        }
        ll mnidx=0,mxidx=0;
        if(!mx.empty())
            mxidx=mx.top().second;
        if(!mn.empty())
            mnidx=mn.top().second;
        a[i]=a[mxidx]+(i-mxidx)*arr[i];
        b[i]=b[mnidx]+(i-mnidx)*arr[i];
        res+=a[i]-b[i];
        mn.push({arr[i],i});
        mx.push({arr[i],i});
    }
    cout<<res;
}