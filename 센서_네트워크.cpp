# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,d;
int dist[110][110];
int ch[110];
int res[110];
int mx;
pair<int,int> arr[110];
int get_dist(pair<int,int> x,pair<int,int> y)
{
    return (x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second);
}
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}
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
    cin>>n>>d;
    d*=d;
    for(int i=1;i<=n;i++)
        cin>>arr[i].first>>arr[i].second;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dist[i][j]=get_dist(arr[i],arr[j]);
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(dist[i][j]>d) continue;
            vector<int> a,b;
            for(int k=1;k<=n;k++)
            {
                if(k==i || k==j) continue;
                if(dist[i][k]>dist[i][j] || dist[j][k]>dist[i][j]) continue;
                int C=ccw(arr[i].first,arr[i].second,arr[j].first,arr[j].second,arr[k].first,arr[k].second);
                if(C>=0) a.push_back(k);
                else b.push_back(k);
            }
            Bipartite_matching B;
            B._init(n,n);
            for(int k=0;k<a.size();k++)
            {
                for(int r=0;r<b.size();r++)
                {
                    if(dist[a[k]][b[r]]>dist[i][j])
                        B._insert(a[k],b[r]);
                }
            }
            int cnt=B._count();
            //cout<<cnt<<'\n';
            B._MinCover();
            vector<int> resA,resB;
            for(int k=1;k<=n;k++)
                if(B.coverA[k]) resA.push_back(k);
            for(int k=1;k<=n;k++)
                if(B.coverB[k]) resB.push_back(k);
            a.push_back(i);
            a.push_back(j);
            //cout<<i<<" "<<j<<" | "<<a.size()<<" "<<b.size()<<" "<<resA.size()<<" "<<resB.size()<<'\n';
            if(mx<a.size()+b.size()-resA.size()-resB.size())
            {
                mx=a.size()+b.size()-resA.size()-resB.size();
                fill(res,res+n+1,0);
                for(auto k:a) res[k]=1;
                for(auto k:b) res[k]=1;
                for(auto k:resA) res[k]=0;
                for(auto k:resB) res[k]=0;
            }
        }
    }
    if(mx==0)
    {
        cout<<1<<'\n';
        cout<<1;
        return 0;
    }
    cout<<mx<<'\n';
    for(int i=1;i<=n;i++)
        if(res[i]) cout<<i<<" ";
}