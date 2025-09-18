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
pll arr[100010];
bool compare(pll a,pll b)
{
    return a.second>b.second;
}
int main()
{
    fastio;
    cin>>n;
    for(int i=0;i<n;i++) 
        cin>>arr[i].first>>arr[i].second;
    sort(arr,arr+n);
    vector<pll> v;
    ll temp=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].second-arr[i].first>=0)
        {
            if(temp<arr[i].first)
            {
                cout<<0;
                return 0;
            }
            else
                temp+=arr[i].second-arr[i].first;
        }
        else v.push_back(arr[i]);
    }
    sort(v.begin(),v.end(),compare);
    for(auto i:v)
    {
        if(temp<i.first)
        {
            cout<<0;
            return 0;
        }
        temp-=i.first-i.second;
    }
    if(temp<0)
        cout<<0;
    else cout<<1;
}