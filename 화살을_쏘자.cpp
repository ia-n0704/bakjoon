# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
map<double,int> m,m2;
int main()
{
    fastio;
    int n,num=0;
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        double a,b;
        cin>>a>>b;
        if(a==0 && b==0)
        {
            num++;
            continue;
        }
        if(a>=0)
        {
            if(b==0)
            {
                m[1000001]++;
                mx=max(mx,m[1000001]);
                continue;
            }
            m[a/b]++;
            mx=max(mx,m[a/b]);            
        }
        else
        {
            if(b==0)
            {
                m2[1000001]++;
                mx=max(mx,m2[1000001]);
                continue;
            }
            m2[a/b]++;
            mx=max(mx,m2[a/b]);
        }
    }
    cout<<mx+num;
}