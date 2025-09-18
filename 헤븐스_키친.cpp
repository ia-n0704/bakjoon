# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
priority_queue<pair<ll,pair<int,int>>> pq; 
ll res;
int par[1010];
vector<int> ans[1010];
pair<ll,ll> arr[1010];
int cnt[1010];
int _find(int x)
{
    if(par[x]==x) return x;
    else return _find(par[x]);
}
void _union(int x,int y)
{
    int px=_find(x),py=_find(y);
    if(px==py) return;
    par[py]=px;
}
void _mst()
{
    for(int i=1;i<=n-1;i++)
    {
        while(!pq.empty())
        {
            auto a=pq.top();
            pq.pop();
            if(_find(a.second.first)!=_find(a.second.second))
            {
                //cout<<a.second.first<<" "<<a.second.second<<" | "<<_find(a.second.first)<<" "<<_find(a.second.second)<<'\n';
                _union(a.second.first,a.second.second);
                res+=a.first;
                ans[a.second.first].push_back(a.second.second);
                ans[a.second.second].push_back(a.second.first);
                cnt[a.second.first]++;
                cnt[a.second.second]++;
                break;
            }
        }
    }
}
void sol()
{
    cin>>n;
    for(int i=1;i<=n;i++) par[i]=i;
    for(int i=1;i<=n;i++)
        cin>>arr[i].first>>arr[i].second;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            ll num=(arr[i].second+arr[j].second)/abs(arr[i].first-arr[j].first);
            pq.push({num,{i,j}});
        }
    }
    _mst();
    cout<<res<<'\n';
    while(1)
    {
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt[i]==1)
            {
                for(auto j:ans[i])
                {
                    if(cnt[j]>0)
                    {
                        cout<<j<<" "<<i<<'\n';
                        cnt[i]--;
                        cnt[j]--;
                        flag=1;
                    }
                }
            }
        }
        if(flag==0) break;
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}