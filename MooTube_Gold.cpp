# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,q;
pair<ll,pll> arr[100010];
pair<pll,ll> query[100010];
ll ans[100010];
int par[100010];
int cnt[100010];
int _find(int x)
{
    if(par[x]==x) return x;
    return _find(par[x]);
}
void _union(int x,int y)
{
    x=_find(x);
    y=_find(y);
    if(x<y) swap(x,y);
    par[y]=x;
    cnt[x]+=cnt[y];
}
int main()
{
    fastio;
    cin>>n>>q;
    for(int i=1;i<n;i++)
        cin>>arr[i].second.first>>arr[i].second.second>>arr[i].first;
    sort(arr+1,arr+n);
    reverse(arr+1,arr+n);
    for(int i=1;i<=q;i++)
    {
        cin>>query[i].first.first>>query[i].first.second;
        query[i].second=i;
    }
    sort(query+1,query+q+1);
    reverse(query+1,query+q+1);
    for(int i=1;i<=n;i++)
    {
        par[i]=i;
        cnt[i]=1;
    }
    int idx=1;
    for(int i=1;i<=q;i++)
    {
        while(arr[idx].first>=query[i].first.first)
        {
            _union(arr[idx].second.first,arr[idx].second.second);
            idx++;
        }
        ans[query[i].second]=cnt[_find(query[i].first.second)];
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]-1<<'\n';
}