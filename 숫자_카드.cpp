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
set<int> s;
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        s.insert(a);
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int a;
        cin>>a;
        if(s.count(a)>0) cout<<1<<" ";
        else cout<<"0 ";
    }
}