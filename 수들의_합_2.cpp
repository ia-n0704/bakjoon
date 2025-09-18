# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m;
int arr[10010],sum[10010];
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sum[i]=sum[i-1]+arr[i];
    }
    int cnt=0;
    int r=1;
    for(int i=1;i<=n;i++)
    {
        while(r<n && sum[r+1]-sum[i-1]<=m) r++;
        if(sum[r]-sum[i-1]==m) cnt++;
    }
    cout<<cnt;
}