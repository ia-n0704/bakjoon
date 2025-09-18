# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int t;
int n,m;
vector<int> v[100010],v2[100010];
int ch[100010];
vector<pair<int,int>> arr;
set<pair<int,int>> s;
void dfs(int x)
{
    for(auto i:v[x])
    {   if(!ch[i])
        {
            s.insert({x,i});
            ch[i]=1;
            dfs(i);
        }
    }
}
void dfs2(int x)
{
    for(auto i:v2[x])
    {   if(!ch[i])
        {
            s.insert({i,x});
            ch[i]=1;
            dfs2(i);
        }
    }
}
int main()
{
    fastio;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            arr.push_back({a,b});
            v[a].push_back(b);
            v2[b].push_back(a);
        }
        fill(ch,ch+n+1,0);
        ch[1]=1;
        dfs(1);
        fill(ch,ch+n+1,0);
        ch[1]=1;
        dfs2(1);
        int remain=m-2*n;
        for(int i=0;i<m;i++)
        {
            if(s.count(arr[i])==0)
            {
                if(remain)
                {
                    remain--;
                    cout<<arr[i].first<<" "<<arr[i].second<<'\n';
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            v[i].clear();
            v2[i].clear();
        }
        arr.clear();
        s.clear();
    }
}