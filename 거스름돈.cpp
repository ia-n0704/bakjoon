# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int cnt=0;
int n;
void go(int a)
{
    while(n>=a)
    {
        n-=a;
        cnt++;
    }
}
int main()
{
    fastio;
    cin>>n;
    n=1000-n;
    go(500);
    go(100);
    go(50);
    go(10);
    go(5);
    go(1);
    cout<<cnt;
}