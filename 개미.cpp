# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int ch[100010];
pair<int,int> par[100010][25];
int n;
int arr[100010];
vector<pair<int,int>> v[100010];
void dfs(int node,int p,int num)
{
    par[node][0]={p,num};
    ch[node]=1;
    for(auto i:v[node])
    {
        if(ch[i.first]==0)
            dfs(i.first,node,i.second);
    }
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n-1;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dfs(1,0,0);
    
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=n;j++)
        {
            par[j][i]={par[par[j][i-1].first][i-1].first,par[j][i-1].second+par[par[j][i-1].first][i-1].second};
        }
    }
    //cout<<par[2][0].first<<'\n';
    for(int i=1;i<=n;i++)
    {
        int num=arr[i];
        int cur=i;
        while(cur!=1)
        {
            int j;
            for(j=20;j>=0;j--)
            {
                if(par[cur][j].first==0) continue;
                if(num-par[cur][j].second>=0)
                {
                    //cout<<j<<'\n';
                    num-=par[cur][j].second;
                    cur=par[cur][j].first;
                    break;
                }
            }
            if(j==-1) break;
            //cout<<cur<<" "<<num<<'\n';
        }
        cout<<cur<<'\n';
    }
}