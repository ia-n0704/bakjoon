# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
ll arr[500010],brr[500010];
ll sum[500010];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>brr[i];
        if(brr[i]!=-1) sum[i]=sum[i-1]+brr[i];
        else sum[i]=sum[i-1];
    }
    sum[n+1]=sum[n];
    ll temp=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]!=-1 && temp+arr[i]<=sum[n]-sum[i])
        {
            cout<<"+";
            temp+=arr[i];
        }
        else if(temp<=sum[n]-sum[i])
            cout<<"0";
        else
        {
            temp-=brr[i];
            cout<<"-";
        }
    }
}