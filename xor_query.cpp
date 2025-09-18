#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100010];
vector<ll> v[100010];
ll ans[100010];
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<=q;i++)
    {
        ll l,r,k;
        cin>>l>>r>>k;
        v[l].push_back(k);
        v[r+1].push_back(k);
    }
    ll temp=0;
    for(int i=1;i<=n;i++)
    {
        for(auto j:v[i])
            temp^=j;
        ans[i]=arr[i]^temp;
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
}