# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define N 100010
#define mx 1e9
typedef pair<int,int> pii;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int HLD_num[N];
int reverse_num[N];
int sz[N];
int n,m;
vector<int> v[N];
pii arr[N];
int chain_num[N];
int chain_head[N];
int chain_par[N];
int seg[N*4];

//Segment_tree
void update(int a,int l,int r,int x)
{
    if(x<l || x>r) return;
    if(l==r)
    {
        if(seg[a]==mx) seg[a]=x;
        else seg[a]=mx;
        //cout<<l<<" "<<r<<" : "<<seg[a]<<"\n";
        return;
    }
    int mid=(l+r)/2;
    update(a*2,l,mid,x);
    update(a*2+1,mid+1,r,x);
    seg[a]=min(seg[a*2],seg[a*2+1]);
    //cout<<l<<" "<<r<<" : "<<seg[a]<<"\n";
}
int query(int a,int l,int r,int st,int en)
{
    if(l>en || r<st) return mx;
    else if(l>=st && r<=en) return seg[a];
    int mid=(l+r)/2;
    return min(query(a*2,l,mid,st,en),query(a*2+1,mid+1,r,st,en));
}
   
//HLD
void get_size(int a,int par)
{
    sz[a]=1;
    for(auto &i:v[a])
    {
        int nx=i;
        if(nx==par) continue;
        get_size(nx,a);
        sz[a]+=sz[nx];
        if(v[a][0]==par || sz[nx]>sz[v[a][0]])
            swap(v[a][0],i);
    }
}
int num;
void dfs(int a,int par,int cnt)
{
    HLD_num[a]=++num;
    reverse_num[num]=a;
    chain_num[a]=cnt;
    if(a==1) update(1,1,n,HLD_num[a]);
    int flag=0;
    for(auto i:v[a])
    {
        int nx=i;
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
        //cout<<HLD_num[nx]<<" "<<nx<<'\n';
        update(1,1,n,HLD_num[nx]);
    }
}

int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n-1;i++)   //input
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    get_size(1,0);
    chain_head[1]=1;
    dfs(1,0,1);
    
    

    cin>>m;     //query
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        if(a==1)
            update(1,1,n,HLD_num[b]);
        else
        {
            //cout<<"answer : "<<HLD_num[b]<<" ";
            int res=mx;                        
            while(chain_head[1]!=chain_head[b])
            {
                res=min(res,query(1,1,n,HLD_num[chain_head[b]],HLD_num[b]));
                //cout<<"| "<<HLD_num[chain_head[b]]<<" "<<HLD_num[b]<<" |";
                b=chain_par[b];
            }
            res=min(res,query(1,1,n,HLD_num[1],HLD_num[b]));
            //cout<<res<<" ";
            if(res==mx) cout<<-1<<'\n';
            else
               cout<<reverse_num[res]<<'\n';
        }
    }
}
     