# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[200010];
void sol()
{
    ll n;
    ll res=0;
    cin>>n;
    map<pair<ll,ll>,ll> m1,m2,m3;
    map<pair<pair<ll,ll>,ll>,ll> s;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        if(i<=n-2) 
        {
            res+=m1[{arr[i],arr[i+1]}]-s[{{arr[i],arr[i+1]},arr[i+2]}];
            res+=m2[{arr[i],arr[i+2]}]-s[{{arr[i],arr[i+1]},arr[i+2]}];
            res+=m3[{arr[i+1],arr[i+2]}]-s[{{arr[i],arr[i+1]},arr[i+2]}];
        }
        //if(s[{{arr[i],arr[i+1]},arr[i+2]}]==0)
        {
            m1[{arr[i],arr[i+1]}]++;
            m2[{arr[i],arr[i+2]}]++;
            m3[{arr[i+1],arr[i+2]}]++;            
        }
        s[{{arr[i],arr[i+1]},arr[i+2]}]++;
    }
    cout<<res<<'\n';
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