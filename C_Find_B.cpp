# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[300010];
ll num[300010];
ll sum[300010];
void sol()
{
    int n,m;
    cin>>n>>m;
    fill(num,num+n+1,0);
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1];
        if(arr[i]==1) sum[i]++;
        num[i]=num[i-1];
        num[i]+=arr[i]-1;
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        if(l==r || num[r]-num[l-1]<sum[r]-sum[l-1])
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
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