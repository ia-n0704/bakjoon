# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
pll arr[100010];
ll dist(pll a,pll b)
{
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
void sol()
{
    int n;
    pll st,en;
    int flag=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i].first>>arr[i].second;
    cin>>st.first>>st.second>>en.first>>en.second;
    ll sd=dist(st,en);
    for(int i=1;i<=n;i++)
    {
        ll td=dist(arr[i],en);
        if(td<=sd) flag=1;
    }
    if(flag) cout<<"NO\n";
    else cout<<"YES\n";
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}