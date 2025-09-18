#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[300010];
ll sum[300010];
ll cnt[300010];
ll num[300010];
ll snum[300010];
ll count(ll p,ll r)
{
    if(r==2) 
        return snum[p-r];
    else if(r==1)
        return num[p-r];
}
void sol()
{
    ll n;
    cin>>n;
    ll res=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        cnt[arr[i]]++;
    }
    for(int i=0;i<=n;i++)
        sum[i]=sum[i-1]+cnt[i];
    for(int i=0;i<=n;i++)
    {
        if(cnt[i]>=2)
        {
            ll temp=0;
            temp+=count(cnt[i],2);
            temp+=count(cnt[i],1)*sum[i-1];
            res+=temp;
        }
    }
    fill(sum,sum+n+5,0);
    fill(cnt,cnt+n+5,0);  
    cout<<res<<'\n';;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=1;i<=300005;i++)
        num[i]=num[i-1]+i;
    for(int i=1;i<=300005;i++)
        snum[i]=snum[i-1]+num[i];
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}