# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
vector<pll> arr;
int main()
{
    fastio;
    ll n,m,t;
    cin>>n>>m>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        if(a<=n && b<=m) arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end());
    vector<ll> v;
    for(auto i:arr) v.push_back(i.second);
    vector<ll> ans;
    ans.push_back(v[0]);
    int temp=0;
    for(int i=1;i<v.size();i++)
    {
        if(v[i]>=ans.back())
        {
            ans.push_back(v[i]);
            temp=ans.size()-1;
        }
        int l=0,r=ans.size()-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(ans[mid]>v[i])
                r=mid-1;
            else l=mid+1;
        }
        ans[l]=v[i];
    }
    cout<<ans.size();
}