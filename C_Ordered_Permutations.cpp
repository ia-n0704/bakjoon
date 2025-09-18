# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll ans[200010];
ll l,r;
void sol()
{
    cin>>n>>k;
    if(n==1 && k==1)
    {
        cout<<"1\n";
        return;
    }
    int flag=0;
    ll kk=k;
    ll t=1;
    for(int i=2;i<=n;i++)
    {
        t*=2;
        if(t>=k)
        {
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        cout<<"-1\n";
        return;
    }
    l=1,r=n;
    k--;
    ll cnt=0;
    ll temp=k;
    while(temp)
    {
        temp/=2;
        cnt++;
    }
    l=1,r=n;
    for(ll i=1;i<=n;i++)
    {
        ll idx=n-i-1;
        if(idx>cnt)
        {
            ans[l++]=i;
            continue;
        }
        if((1ll<<idx)&k)
            ans[r--]=i;
        else ans[l++]=i;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    cout<<'\n';
    fill(ans,ans+n+1,0);
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