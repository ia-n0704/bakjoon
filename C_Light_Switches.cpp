# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll arr[200010];
void sol()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    vector<ll> v;
    ll mx=0;
    for(int i=1;i<=n;i++)
    {
        ll st=arr[i];
        ll num=st/(2*k);
        st-=num*(k*2);
        v.push_back(st);
        mx=max(mx,arr[i]);
    }
    sort(v.begin(),v.end());
    int flag=0;
    pair<ll,ll> num;
    num.second=v[0]+k-1;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]<=num.second)
            num.first=v[i];
        else if((v[i]+k-1)/(2*k) && (v[i]+k-1)%(2*k)>=num.first)
            num.second=(v[i]+k-1)%(2*k);
        else flag=1;
    }
    if(num.first<mx)
    {
        ll temp=mx/(k*2);
        num.first+=temp*k*2;
    }
    if(mx>num.first) num.first+=k*2;
    if(flag)
    {
        cout<<-1<<'\n';
    }
    else cout<<num.first<<'\n';
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