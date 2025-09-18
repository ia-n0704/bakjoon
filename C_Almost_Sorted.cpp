# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define mod 998244353
int n,d;
int arr[100010];
int ch[100010];
int dp[505][20];
int main()
{
    fastio;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]!=-1) ch[arr[i]]=1;
    }
    for(int i=1;i<=n;i++)
    {
        
    }
}