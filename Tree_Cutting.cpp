# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
vector<int> v[10010];
int sz[10010];
int ch[10010];
int dfs(int x)
{
    int num=0;
    ch[x]=1;
    for(auto i:v[x])
    {
        if(ch[i]==0)
            num+=dfs(i);
    }
    return sz[x]=num+1;
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    sz[1]=dfs(1);
    fill(ch,ch+n+1,0);
    int idx=1;
    while(1)
    {
        ch[idx]=1;
        int nx=0;
        for(auto i:v[idx])
        {
            if(ch[i]==0 && sz[i]>n/2)
            {
                nx=i;
                break;
            }
        }
        if(!nx) break;
        idx=nx;
    }
    vector<int> res;
    res.push_back(idx);
    for(auto i:v[idx])
    {
        if(sz[i]==(n+1)/2)
        {
            res.push_back(i);
            break;
        }
    }
    sort(res.begin(),res.end());
    for(auto i:res) cout<<i<<"\n";
}