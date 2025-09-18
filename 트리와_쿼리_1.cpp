# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define N 100010
typedef pair<int,int> pii;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int HLD_num[N];
int sz[N];
int n,m;
vector<pii> v[N];
pii arr[N];
int chain_num[N];
int chain_head[N];
int chain_par[N];
int seg[N*4];

//Segment_tree
void update(int a,int l,int r,int x,int co)
{
    if(x<l || x>r) return;
    if(l==r)
    {
        seg[a]=co;
        return;
    }
    int mid=(l+r)/2;
    update(a*2,l,mid,x,co);
    update(a*2+1,mid+1,r,x,co);
    seg[a]=max(seg[a*2],seg[a*2+1]);
}
int query(int a,int l,int r,int st,int en)
{
    if(l>en || r<st) return 0;
    else if(l>=st && r<=en) return seg[a];
    int mid=(l+r)/2;
    return max(query(a*2,l,mid,st,en),query(a*2+1,mid+1,r,st,en));
}

//HLD
void get_size(int a,int par)
{
    sz[a]=1;
    for(auto &i:v[a])
    {
        int nx=i.first;
        if(nx==par) continue;
        get_size(nx,a);
        sz[a]+=sz[nx];
        if(v[a][0].first==par || sz[nx]>sz[v[a][0].first])
            swap(v[a][0],i);
    }
}
int num;
void dfs(int a,int par,int cnt)
{
    HLD_num[a]=++num;
    chain_num[a]=cnt;
    int flag=0;
    for(auto i:v[a])
    {
        int nx=i.first;
        if(nx==par) continue;
        if(!flag)
        {
            chain_head[nx]=chain_head[a];
            chain_par[nx]=chain_par[a];
            dfs(nx,a,cnt);
            flag=1;
        }
        else
        {
            chain_head[nx]=nx;
            chain_par[nx]=a;
            dfs(nx,a,cnt+1);
        }
        update(1,1,n,HLD_num[nx],i.second);
    }
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n-1;i++)   //input
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
        arr[i]={a,b};
    }
     
    get_size(1,0);
    
    dfs(1,0,1);
    chain_head[1]=1;
    

    cin>>m;     //query
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            if(HLD_num[arr[b].first]>HLD_num[arr[b].second])
                swap(arr[b].first,arr[b].second);
            update(1,1,n,HLD_num[arr[b].second],c);
        }
        else
        {
            int res=0;                        
            if(chain_num[b]>chain_num[c]) swap(b,c);
            while(chain_num[b]<chain_num[c])
            {
                res=max(res,query(1,1,n,HLD_num[chain_head[c]],HLD_num[c]));
                c=chain_par[c];
            }
            while(chain_head[b]!=chain_head[c])
            {
                res=max(res,query(1,1,n,HLD_num[chain_head[b]],HLD_num[b]));
                res=max(res,query(1,1,n,HLD_num[chain_head[c]],HLD_num[c]));
                b=chain_par[b];
                c=chain_par[c];
            }
            if(HLD_num[b]>HLD_num[c]) swap(b,c);
            res=max(res,query(1,1,n,HLD_num[b]+1,HLD_num[c]));
            cout<<res<<'\n';
        }
    }
}
