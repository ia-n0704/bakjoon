# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,q;
vector<int> v[100010];
int depth[100010];
int ch[100010];
int par[100010][100];
void dfs(int node,int d,int last)
{
    depth[node]=d;
    ch[node]=1;
    par[node][0]=last;
    int idx=1;
    for(int i=1;i<=d;i*=2)
    {
        par[node][idx]=par[par[node][idx-1]][idx-1];
        idx++;
    }
    for(auto i:v[node])
    {
        if(ch[i]==0)
            dfs(i,d+1,node);
    }
}
int lca(int a,int b)
{
    if(depth[a]<depth[b])
        swap(a,b);
    for(int i=20;i>=0;i--)
    {
        if(depth[a]-depth[b]>=(1<<i))
            a=par[a][i];
    }
    if(a==b) return a;
    for(int i=20;i>=0;i--)
    {
        if(par[a][i]!=par[b][i])
        {
            a=par[a][i];
            b=par[b][i];
        }
    }
    return par[a][0];
}
int main()
{
    fastio;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0,0);
    cin>>q;
    while(q--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        //1 a,b
        int k=lca(a,b);
        int dis=(abs(depth[k]-depth[a])+abs(depth[k]-depth[b]))/2;
        int dis2=dis;
        if((abs(depth[k]-depth[a])+abs(depth[k]-depth[b]))%2==0)
        {
            int x;
            if(depth[a]>=depth[b])
                x=a;
            else x=b;
            for(int i=20;i>=0;i--)
            {
                if(dis>=(1<<i))
                {
                    x=par[x][i];
                    dis-=(1<<i);
                }
            }
            int t=lca(x,c);
            if(dis2==abs(depth[t]-depth[x])+abs(depth[t]-depth[c]))
            {
                cout<<x<<'\n';
                continue;
            }
        }
        //2 b,c
        k=lca(b,c);
        dis=(abs(depth[k]-depth[b])+abs(depth[k]-depth[c]))/2;
        dis2=dis;
        if((abs(depth[k]-depth[b])+abs(depth[k]-depth[c]))%2==0)
        {
            int x;
            if(depth[b]>=depth[c])
                x=b;
            else x=c;
            for(int i=20;i>=0;i--)
            {
                if(dis>=(1<<i))
                {
                    x=par[x][i];
                    dis-=(1<<i);
                }
            }
            int t=lca(x,a);
            if(dis2==abs(depth[t]-depth[x])+abs(depth[t]-depth[a]))
            {
                cout<<x<<'\n';
                continue;
            }
        }
        //3 a,c
        k=lca(a,c);
        dis=(abs(depth[k]-depth[a])+abs(depth[k]-depth[c]))/2;
        dis2=dis;
        if((abs(depth[k]-depth[a])+abs(depth[k]-depth[c]))%2==0)
        {
            int x;
            if(depth[a]>=depth[c])
                x=a;
            else x=c;
            for(int i=20;i>=0;i--)
            {
                if(dis>=(1<<i))
                {
                    x=par[x][i];
                    dis-=(1<<i);
                }
            }
            int t=lca(x,b);
            if(dis2==abs(depth[t]-depth[x])+abs(depth[t]-depth[b]))
            {
                cout<<x<<'\n';
                continue;
            }
        }
        cout<<-1<<'\n';
    }

}