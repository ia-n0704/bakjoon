# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,m;
vector<ll> v[100010];
ll ch[100010];
ll mn=(ll)1e9;
ll mnidx;
ll res;
void bfs(ll st)
{
    queue<pair<ll,ll>> q;
    q.push({st,0});
    while(!q.empty())
    {
        auto a=q.front();
        q.pop();
        for(auto i:v[a.first])
        {
            if(i==a.second) continue;
            if(ch[i])
            {
                //cout<<a.first<<" "<<i<<" "<<ch[i]<<" "<<ch[a.first]<<'\n';
                if(mn>=ch[i]+ch[a.first]-1)
                {
                    if(mn==ch[i]+ch[a.first]-1)
                        mnidx++;
                    else
                    {
                        mn=ch[i]+ch[a.first]-1;
                        mnidx=1;
                        res=0;
                    }
                }
                continue;
            }
            ch[i]=ch[a.first]+1;
            q.push({i,a.first});
        }        
    }

}
int main()
{
    fastio;
    cin>>n>>m;
    for(ll i=1;i<=m;i++)
    {
        ll a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(ll i=1;i<=n;i++)
    {
        ch[i]=1;
        bfs(i);
        res+=mnidx;
        cout<<res<<'\n';
        mnidx=0;
        fill(ch+1,ch+n+1,0);
    }
    cout<<res/mn/2;
}