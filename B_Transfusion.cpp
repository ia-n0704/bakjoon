# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll arr[200010];
void sol()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    ll sum=0;
    for(int i=1;i<=n;i++) sum+=arr[i];
    ll num=0;
    if(sum%n!=0)
    {
        cout<<"NO\n";
        return;
    }
    num=sum/n;
    sum=0;
    for(int i=1;i<=n;i+=2)
        sum+=arr[i];
    if(sum!=num*(n/2+n%2))
    {
        cout<<"NO\n";
        return;
    }
    sum=0;
    for(int i=2;i<=n;i+=2)
        sum+=arr[i];
    if(sum!=num*(n/2))
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
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