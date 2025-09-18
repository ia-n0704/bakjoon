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
pair<ll,ll> arr[100010];
pair<ll,ll> brr[100010];
vector<ll> v[100010];
ll ch[100010];
ll mn=1e18;

int main()
{
    fastio;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>arr[i].first;
        arr[i].second=i;
        brr[i]=arr[i];
        mn=min(mn,arr[i].first);
    }
    sort(brr+1,brr+n+1);
    ll num=0;
    for(ll i=1;i<=n;i++)
    {
        if(ch[i]) continue;
        ll cur=i;
        while(ch[cur]==0)
        {
            v[num].push_back(arr[cur].first);
            ch[cur]++;
            cur=brr[cur].second;
        }
        num++;
    }
    ll res=0;
    for(ll i=0;i<num;i++)
    {
        ll mn2=1e18;
        ll sum=0;
        for(auto j:v[i])
        {
            sum+=j;
            mn2=min(mn2,j);
        }
        res+=min(sum+mn2*(v[i].size()-2),sum+mn2+mn*(v[i].size()+1));
    }
    cout<<res;
}