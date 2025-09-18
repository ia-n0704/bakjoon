# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll,ll> arr[1000010],brr[1000010];
ll dp[1000010];
ll c[1000010];
bool compare(pair<ll,ll> a,pair<ll,ll> b)
{
    if(a.first-a.second==b.first-b.second)
        return a.first<b.first;
    return a.first-a.second<b.first-b.second;
}
void sol()
{
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>arr[i].first;
    for(int i=1;i<=n;i++)
        cin>>arr[i].second;
    for(int i=1;i<=n;i++) brr[i]=arr[i];
    for(int i=1;i<=m;i++) cin>>c[i]; 
    sort(arr+1,arr+n+1,compare); 
    sort(brr+1,brr+n+1); 
    ll idx=1;
    ll mn=brr[1].first-brr[1].second;
    dp[brr[idx++].first]=1;
    for(int i=brr[1].first+1;i<=1000000;i++)
    {
        while(idx<=n && brr[idx].first<=i)
        {
            mn=min(mn,brr[idx].first-brr[idx].second);
            idx++;
        }
        dp[i]=max(dp[i-1],dp[i-mn]+1);
    }
    ll cnt=0;
    for(int i=1;i<=m;i++)
    {
        if(c[i]>1000000)
        {
            ll temp=(c[i]-1000000)/mn+1;
            cnt+=temp;
            c[i]-=temp*mn;
        }
        cnt+=dp[c[i]];
        //cout<<" | "<<cnt<<'\n';
    }  
    cout<<cnt*2;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}