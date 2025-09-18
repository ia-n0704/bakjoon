# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
struct Bipartite_matching
{
    int N;
    vector<int> v[1010];
    int ans[1010];
    int ch[1010];
    void _init(int n)
    {
        N=n;
        fill(ans,ans+N+1,0);
    }
    void _insert(int a,int b)
    {
        v[a].push_back(b);
        //cout<<a<<" "<<b<<'\n';
    }
    int _go(int x)
    {
        ch[x]=1;
        for(auto i:v[x])
        {
            if(!ans[i])
            {
                ans[i]=x;
                return 1;
            }
            if(!ch[ans[i]] && _go(ans[i]))
            {
                ans[i]=x;
                return 1;
            }
        }
        return 0;
    }
    int _count()
    {
        int res=0;
        for(int i=1;i<=N;i++)
        {
            fill(ch,ch+N+1,0);
            res+=_go(i);
        }
        return res;
    }
};
int main()
{
    fastio;
    int n,m;
    cin>>n>>m;
    Bipartite_matching B;
    B._init(n);
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        for(int j=1;j<=t;j++)
        {
            int a;
            cin>>a;
            B._insert(i,a);
        }
    }
    cout<<B._count();
}