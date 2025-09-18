# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m;
pair<int,int> arr[100010],brr[100010];
int cnt;
ll res;
multiset<pair<int,int>> s;
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>arr[i].first>>arr[i].second;
    for(int i=1;i<=m;i++)
        cin>>brr[i].first>>brr[i].second;
    sort(arr+1,arr+n+1);
    sort(brr+1,brr+m+1);
    int idx=1;
    for(int i=1;i<=m;i++)
    {
        while(idx<=n && arr[idx].first<=brr[i].first)
            s.insert({arr[idx].second,idx++});
        /*for(auto j=s.begin();j!=s.end();j++)
            cout<<(*j).first<<" "<<(*j).second<<'\n';
        cout<<'\n';*/
        auto num=s.lower_bound({brr[i].second,n+1});
        //cout<<" | "<<brr[i].second<<" "<<(*num).first<<'\n';
        if(num!=s.begin())
        {
            num--;
            res+=(ll)brr[i].first;
            cnt++;
            s.erase(num);
            //cout<<res<<'\n';
        }
    }
    if(cnt==n)
       cout<<res;
    else cout<<-1;
}