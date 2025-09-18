# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll MAX=1e9+7;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
vector<ll> v[2020];
pair<ll,ll> arr[2020];
ll n,m;
ll num;
ll ch[2020];
ll temp[2020];
int go(ll a)
{
    ch[a]=1;
    if(a==n-1) return 1;
    int res=0;
    for(auto i:v[a])
    {
        if(ch[i]==0)
            res=max(res,go(i));
    }
    return res;
}
int main()
{
    fastio;
    cin>>n>>m;
    ll three=1;
    for(int i=0;i<m;i++)
    {
        cin>>arr[i].first>>arr[i].second;
        temp[i]=three;
        three*=3;
        three%=mod;
    }
    for(int i=m-1;i>=0;i--)
    {
        fill(ch,ch+m,0);
        auto t=arr[i];
        v[t.first].push_back(t.second);
        v[t.second].push_back(t.first);
        if(go(0)==1)
        {
            v[t.first].pop_back();
            v[t.second].pop_back();
            num+=temp[i];
            num%=mod;
        }
    }
    cout<<num;
}