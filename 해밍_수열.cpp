# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
vector<ull> v;
vector<ull> x,y,z;
vector<ull> ans;
const ull mx=1e18;
int main()
{
    fastio;
    ull a,b,c,d;
    cin>>a>>b>>c>>d;
    ull temp=1;
    while(temp<=mx)
    {
        x.push_back(temp);
        temp*=a;
    }
    temp=1;
    while(temp<=mx)
    {
        y.push_back(temp);
        temp*=b;
    }
    temp=1;
    while(temp<=mx)
    {
        z.push_back(temp);
        temp*=c;
    }
    for(auto i:x)
    {
        for(auto j:y)
        {
            if(i*j>mx) continue;
            for(auto k:z)
            {
                if(i*j*k>mx) continue;
                ans.push_back(i*j*k);
            }
        }
    }
    sort(ans.begin(),ans.end());
    //for(int i) cout<<i<<" ";
    cout<<ans[d];
}