#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
ll c[200010],t[200010];
vector<ll> arr;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>c[i];
    for(int i=0;i<n;i++)
    {
        cin>>t[i];
        if(c[i]-t[i]-1>0)
            arr.push_back(c[i]-t[i]);
    }
    sort(arr.begin(),arr.end());
    while(q--)
    {
        ll v,s;
        cin>>v>>s;
        ll num=arr.size()-(upper_bound(arr.begin(),arr.end(),s)-arr.begin());
        if(num>=v) cout<<"YES\n";
        else cout<<"NO\n";
    }
}