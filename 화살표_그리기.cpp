#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
pair<ll,ll> arr[100010];
vector<ll> v[100010];
int main()
{
    cin>>n;
    vector<ll> v2;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
        v[arr[i].second].push_back(arr[i].first);
        v2.push_back(arr[i].second);
    }
    sort(v2.begin(),v2.end());
    v2.erase(unique(v2.begin(),v2.end()),v2.end());
    for(auto i:v2)
        sort(v[i].begin(),v[i].end());
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int idx=lower_bound(v[arr[i].second].begin(),v[arr[i].second].end(),arr[i].first)-v[arr[i].second].begin();
        ll res=1e16;
        if(idx>0)
            res=arr[i].first-v[arr[i].second][idx-1];
        if(idx<v[arr[i].second].size()-1)
            res=min(res,v[arr[i].second][idx+1]-arr[i].first);
        if(res==1e16) res=0;
        ans+=res;
    }
    cout<<ans;
}