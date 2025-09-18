#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1000010];
ll sum[1000010];
int ch[1010];
ll f(ll a)
{
    return a*(a-1)/2;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sum[i]=(sum[i-1]+arr[i])%m;
        ch[sum[i]]++;
    }
    ll res=0;
    for(int i=0;i<m;i++)
        res+=ch[i]?f((ll)ch[i]):0;
    res+=ch[0];
    cout<<res;
}