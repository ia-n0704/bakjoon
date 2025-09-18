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
    int N,M;
    vector<int> v[10010];
    int ansA[10010],ansB[10010];
    int ch[10010];
    void _init(int n,int m)
    {
        N=n;
        M=m;
        fill(ansA,ansA+N+1,0);
        fill(ansB,ansB+M+1,0);
        for(int i=1;i<=N;i++)
            v[i].clear();
        fill(ch,ch+N+1,0);
    }
    void _insert(int a,int b)
    {
        v[a].push_back(b);
    }
    int _go(int x)
    {
        ch[x]=1;
        for(auto i:v[x])
        {
            if(!ansB[i])
            {
                ansB[i]=x;
                ansA[x]=i;
                return 1;
            }
            if(!ch[ansB[i]] && _go(ansB[i]))
            {
                ansB[i]=x;
                ansA[x]=i;
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
    int coverA[10010],coverB[10010];
    int ch2[10010];
    void _CoverInit(int n,int m)
    {
        fill(coverA,coverA+n+1,0);
        fill(coverB,coverB+m+1,0);
        fill(ch2,ch2+n+1,0);
    }
    void _FindCover(int x)
    {
        ch2[x]=1;
        for(auto i:v[x])
        {
            coverB[i]=1;
            if(ch2[ansB[i]]==0)
                _FindCover(ansB[i]);
        }
    }
    void _MinCover()
    {
        _CoverInit(N,M);
        for(int i=1;i<=N;i++)
        {
            if(ansA[i]==0) _FindCover(i);
        }
        for(int i=1;i<=N;i++)
        {
            if(ansA[i] && ch2[i]==0) coverA[i]=1;
        }
    }
};
int main()
{
    fastio;
    Bipartite_matching B;
    int n,m;
    cin>>n>>m;
    B._init(m,m);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        B._insert(a,b);
    }
    cout<<B._count();
}