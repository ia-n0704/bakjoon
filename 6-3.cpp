#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> dp[31];
ll arr[31];
vector<ll> v,vv;
int main()
{
    ll n,m,num,s=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        s+=arr[i];
    }
    dp[1].insert(arr[1]);
    v.push_back(arr[1]);
    for(int i=2;i<=n;i++)
    {
        dp[i].insert(arr[i]);
        vv=v;
        v.clear();
        v.push_back(arr[i]);
        for(auto j:vv)
        {
            dp[i].insert(j);
            v.push_back(j);
            dp[i].insert(j+arr[i]);
            v.push_back(arr[i]+j);
            dp[i].insert(abs(arr[i]-j));
            v.push_back(abs(arr[i]-j));
        }
    }
    cin>>m;
    while(m--)
    {
        ll a;
        cin>>a;
        if(dp[n].count(a))
            printf("Y ");
        else
            printf("N ");
    }
}