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
pair<int,int> arr[200010];
int main()
{
    fastio;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].second>>arr[i].first;
    }
    sort(arr,arr+n);
    int mn=arr[0].second;
    int res=mn;
    for(int i=1;i<n;i++)
    {
        if(arr[i].first!=arr[i-1].first)
        {
            mn=arr[i].second;
            res=max(res,mn);
        }
    }
    cout<<res;
}