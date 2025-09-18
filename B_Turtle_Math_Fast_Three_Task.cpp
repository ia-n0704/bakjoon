# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef long long ll;
ll arr[100010],ch[100010];
void Y()
{
    cout<<"YES\n";
}
void N()
{
    cout<<"NO\n";
}
void sol()
{
    int n;
    ll sum=0;
    cin>>n;
    for(int i=0;i<n;i++) 
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    for(int i=0;i<n;i++)
        ch[i]=arr[i]%3;
    int res=3-sum%3;
    if(sum%3==0) res=0;
    for(int i=0;i<n;i++)
    {
        if((sum-arr[i])%3==0)
            res=min(res,1);
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
        sol();
}