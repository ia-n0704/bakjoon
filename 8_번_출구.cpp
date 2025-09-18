#include <bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
ll arr[200010];
ll sum[200010];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sum[i]=sum[i-1]+arr[i];
    }
    ll mx=0;
    ll cur=0;
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        if(cur>=arr[i])
        {
            cur-=arr[i];
            continue;
        }
        mx=max(mx,arr[i]-sum[i-1]);
        ll cnt=(arr[i]-cur)/mx;
        cur+=cnt*mx;
        if(cur<arr[i])
        {
            cur+=mx;
            cnt++;
        }
        res+=cnt;
        cur-=arr[i];
        //cout<<i<<" | "<<cur<<" "<<res<<'\n';
    }
    cout<<res;
}