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
int t;
int main()
{
    fastio;
    cin>>n>>m;
    cin>>t;
    int flag=0;
    for(int i=1;i<=t;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a%2 && b%2) flag=1;
    }
    if(n%2 && m%2) cout<<n/2+m/2+flag;
    else cout<<n/2+m/2;
}