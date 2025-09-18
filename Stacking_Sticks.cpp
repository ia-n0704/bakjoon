# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
map<int,int> m;
int main()
{
    fastio;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a==1)
        {
            int mx=max(max(m[b],m[b+1]),max(m[b+2],m[b+3]));
            m[b]=m[b+1]=m[b+2]=m[b+3]=mx+1;
        }
        else if(a==2)
            m[b]+=4;
        else cout<<m[b]<<'\n';
    }
}