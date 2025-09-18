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
int arr[1001];
int isprime[1001];
int main()
{
    fastio;
    isprime[1]=1;
    for(int i=2;i<=1000;i++)
    {
        if(isprime[i]) continue;
        for(int j=i*2;j<=1000;j+=i)
            isprime[j]=1;
    }
    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(isprime[x]==0) cnt++;
    }
    cout<<cnt;
}