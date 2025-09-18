# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
vector<pll> num;
ll f(ll n,ll s,ll e)
{
    ll ans=0;
    ll i=s;
    while(i<=n && i<=e)
    {
        ll j=n/(n/i);
        ans+=(n/i)*(min(j,e)-i+1);
        if(j>e) break;
        i=j+1;
    }
    return ans;
}
int main()
{
    fastio;
    ll n,s,e;
    int q;
    cin>>q;
    int flag=0;
    ll a=-1;
    vector<pair<ll,pll>> v;
    while(q--)
    {
        cin>>n>>s>>e;
        v.push_back({n,{s,e}});
        if(a!=-1 && n!=a) flag=1;
        a=n;
    }
    if(!flag)
    {
        ll i=1;
        ll ans=0;
        while(i<=n)
        {
            ll j=n/(n/i);
            ans+=(n/i)*(n-i+1);
            i=j+1;
            num.push_back({j,ans});
        }
        num.push_back({i,ans});
        for(auto i:v)
        {
            ll a=i.first;
            ll b=i.second.first;
            ll c=i.second.second;
            int l=0,r=num.size()-1;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(num[mid].first>c) r=mid;
                else l=mid+1;
            }
            int idx2=l;
            l=0,r=num.size()-1;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(num[mid].first>b) r=mid;
                else l=mid+1;
            }
            int idx1=l;
            cout<<idx1<<" "<<idx2<<" "<<num[idx2].second<<'\n';
            cout<<num[idx1].second-num[idx2].second+f(n,b,num[idx2].first)+f(n,c+1,num[idx1].first)<<'\n';
        }
    }
    else
    {
        for(auto i:v)
            cout<<f(i.first,i.second.first,i.second.second)<<'\n';
    }
}