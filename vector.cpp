# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
vector<int> v[100010];
int n,m;
int t;
int main()
{
    fastio;
    cin>>n>>m>>t;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(t==0)
            v[a].push_back(b);
        else
        {
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }
    for(int i=0;i<n;i++)
        sort(v[i].begin(),v[i].end());
    for(int i=0;i<n;i++)
    {
        cout<<v[i].size()<<" ";
        for(auto j:v[i]) cout<<j<<" ";
        cout<<'\n';
    }
}