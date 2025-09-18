# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll l,r;
ll two[100];
int main()
{
    fastio;
    cin>>l>>r;
    two[0]=1;
    for(int i=1;i<=63;i++) two[i]=two[i-1]*2;
    int idx1=lower_bound(two,two+64,l)-two;
    int idx2=lower_bound(two,two+64,r)-two-1;
    
}