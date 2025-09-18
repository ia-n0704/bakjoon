# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m;
vector<int> v[500010];
ll arr[500010];
int num[500010];
ll lazy[2000010];
ll seg[2000010];
pair<int,int> range[500010];
int cnt;
void dfs(int x)
{
    int st=++cnt,en;
    num[x]=st;
    for(auto i:v[x])
        if(num[i]==0) dfs(i);
    en=cnt;
    range[x]={st,en};
}
void prop(int v,int l,int r)
{
    seg[v]+=(r-l+1)*lazy[v];
    if(l==r)
    {
        lazy[v]=0;
        return;
    }
    for(auto i:{v*2,v*2+1})
        lazy[i]+=lazy[v];
    lazy[v]=0;
}
void update(int v,int l,int r,int st,int en,ll x)
{
    prop(v,l,r);
    if(st>r || en<l) return;
    if(st<=l && en>=r)
    {
        lazy[v]+=x;
        prop(v,l,r);
        return;
    }
    int mid=(l+r)/2;
    update(v*2,l,mid,st,en,x);
    update(v*2+1,mid+1,r,st,en,x);
    seg[v]=seg[v*2]+seg[v*2+1];
}
ll query(int v,int l,int r,int idx)
{
    prop(v,l,r);
    if(r<idx || l>idx) return 0;
    if(l==r) return seg[v];
    int mid=(l+r)/2;
    return query(v*2,l,mid,idx)+query(v*2+1,mid+1,r,idx);
}
int main()
{
    fastio;
    cin>>n>>m;
    cin>>arr[1];
    for(int i=2;i<=n;i++)
    {
        int a;
        cin>>arr[i]>>a;
        v[a].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
        update(1,1,n,num[i],num[i],arr[i]);
    while(m--)
    {
        char c;
        ll a,b;
        cin>>c;
        if(c=='p')
        {
            cin>>a>>b;
            update(1,1,n,range[a].first+1,range[a].second,b);
        }
        else
        {
            cin>>a;
            cout<<query(1,1,n,num[a])<<'\n';
        }
    }
}