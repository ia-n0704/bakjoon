# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,m,k;
pll arr[200010];
pll brr[200010];
ll res;
vector<ll> ans;
int main()
{
    fastio;
    cin>>n>>m>>k;
    priority_queue<ll> pq;
    for(int i=1;i<=n;i++)
        cin>>arr[i].first>>arr[i].second;
    for(int i=1;i<=m;i++)
        cin>>brr[i].second>>brr[i].first;
    sort(arr+1,arr+n+1);
    sort(brr+1,brr+m+1);
    int idx=1;
    for(int i=1;i<=n;i++)
    {
        if(k==0) break;
        int j;
        for(j=idx;j<=m;j++)
        {
            if(arr[i].second>=brr[j].first)
                pq.push(brr[j].second);
            else break;
        }
        idx=j;

        if(pq.empty()) continue;
        ll a=pq.top(); pq.pop();
        ans.push_back(a-arr[i].first);
        cout<<a<<" "<<arr[i].first<<'\n';
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<min(k,(ll)ans.size());i++)
        res+=max(0ll,ans[ans.size()-i-1]);
    cout<<res;
}