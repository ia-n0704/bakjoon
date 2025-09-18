# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b;
void sol()
{
    cin>>n>>a>>b;
    if(a==0)
    {
        if(b>=n) cout<<n<<'\n';
        else if(b>=n-2) cout<<n-1<<'\n';
        else cout<<"-1\n";
        return;
    }
    if(n-1<b)
    {
        cout<<n<<'\n';
        return;
    }
    ll num=(n-b-1)/a+1;
    cout<<n-num<<'\n';
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