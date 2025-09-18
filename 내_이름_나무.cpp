# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin,(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n,m,k;
int w;
string name[35010];
vector<int> v[35010];
int dist[35010];
int ch[35010],check[35010];
set<string> s;
int main()
{
    fastio;
    int n,m,k,w;
    cin>>n>>m>>k>>w;
    for(int i=1;i<=w;i++)
    {
        int a;
        string t;
        cin>>a>>t;
        name[a]=t;
        ch[a]=1;
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        if(!ch[i]) continue;
        queue<pii> q;

        fill(dist,dist+n+1,-1);
        for(int j=1;j<=n;j++)
        {
            if(check[j]==1) continue;
            if(name[i]==name[j])
            {
                q.push({j,0});
                check[j]=1;
                dist[j]=1e9;
            }
        }        
        while(!q.empty())
        {
            auto a=q.front();
            q.pop();
            for(auto x:v[a.first])
            {
                dist[x]=min(dist[x],a.second+1);
                q.push({x,a.second+1});
            }
        }
        for(int j=1;j<=n;j++)
        {
            if(i==j ||dist[j]==1e9 || name[i]!=name[j]) continue;
            if(dist[j]<=k)
            {
                //cout<<i<<" "<<j<<" | "<<dist[j]<<'\n';
                flag=1;
            }
        }
        fill(dist,dist+n+1,0);
    }
    if(flag) cout<<"POWERFUL CODING JungHwan";
    else cout<<"so sad";
}