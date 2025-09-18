#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll c[2010];
pair<pair<ll,ll>,ll> arr[4010];
vector<pair<ll,pair<ll,ll>>> v[2010];
vector<pair<ll,ll>> v_new[2010];
int ch[4010];
int par[4010];
int ch2[2010];
ll A,b;
int _find(int x)
{
    if(x==par[x]) return x;
    return par[x]=_find(par[x]);
}
void _union(int x,int y)
{
    x=_find(x);
    y=_find(y);
    par[y]=x;
    //cout<<x<<" "<<y<<" "<<arr[x].first.first<<" "<<arr[y].first.second<<" "<<arr[x].second<<'\n';
    arr[x].second+=arr[y].second;
    arr[x].first.second=arr[y].first.second;
}
void dfs(int cur,int p)
{
    for(auto i:v[cur])
    {
        if(p!=0 && (c[cur] || arr[_find(p)].second+arr[_find(i.first)].second<=A))
        {
            _union(p,i.first);
        }
        if(ch[i.first]) continue;
        ch[i.first]=1;
        dfs(i.second.first,i.first);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin>>n>>m;
    for(ll i=1;i<=m;i++)
    {
        ll x,y,t;
        cin>>x>>y>>t;
        arr[i]={{x,y},t};
        v[x].push_back({i,{y,t}});
        par[i]=i;
    }
    for(ll i=1;i<=n;i++) cin>>c[i];
    cin>>A>>b;
    dfs(1,0);
    for(int i=1;i<=m;i++)
    {
        if(_find(i)==i)
        {
            //cout<<arr[i].first.second<<" ";
            v_new[arr[i].first.first].push_back({arr[i].first.second,arr[i].second});
        }
    }
    queue<pair<ll,ll>> q;
    q.push({1,0});
    while(!q.empty())
    {
        auto tt=q.front();
        //cout<<a.first<<" "<<a.second<<'\n';
        q.pop();
        ch2[tt.first]=1;
        for(auto i:v_new[tt.first])
        {
            if(ch2[i.first] || i.second>A) continue;
            q.push({i.first,tt.second+1});
            if(i.first==n)
            {
                cout<<tt.second*(A+b)+i.second;
                return 0;
            }
        }
    }
    cout<<-1;
}