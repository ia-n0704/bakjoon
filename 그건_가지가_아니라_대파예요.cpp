#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
const ll mod=998'244'353;
const ll MOD=1e9+7;
struct UF
{
    vector<int> par;
    void _init(int n)
    {
        par.resize(n+1);
        iota(all(par),0);
    }
    int _find(int x)
    {
        if(par[x]==x) return x;
        return par[x]=_find(par[x]);
    }
    void _merge(int x,int y)
    {
        int fx=_find(x),fy=_find(y);
        if(fx==fy) return;
        if(fx>fy) swap(fx,fy);
        par[fy]=fx; 
    }
};
struct MaxSeg
{
    vector<ll> arr;
    vector<ll> seg;
    ll seg_init(int v,int l,int r)
    {
        if(l==r)
        {
            seg[v]=arr[l];
            return seg[v];
        }
        int mid=(l+r)/2;
        return seg[v]=max(seg_init(v*2,l,mid),seg_init(v*2+1,mid+1,r));
    }
    void _init(int n,vector<ll> t)
    {
        arr.resize(n+10);
        seg.resize(n*4+10);
        for(int i=0;i<t.size();i++)
            arr[i]=t[i];
        seg_init(1,0,n-1);
    }
    void update(int v,int l,int r,int idx,ll num)
    {
        if(l>idx || r<idx) return;
        if(l==r)
        {
            seg[v]=num;
            return;
        }
        int mid=(l+r)/2;
        update(v*2,l,mid,idx,num);
        update(v*2+1,mid+1,r,idx,num);
        seg[v]=max(seg[v*2],seg[v*2+1]);
    }
    ll query(int v,int l,int r,int s,int e)
    {
        if(l>e || r<s) return -1e18;
        if(l>=s && r<=e) return seg[v];
        int mid=(l+r)/2;
        return max(query(v*2,l,mid,s,e),query(v*2+1,mid+1,r,s,e));
    }
};
struct MinSeg
{
    vector<ll> arr;
    vector<ll> seg;
    ll seg_init(int v,int l,int r)
    {
        if(l==r)
        {
            seg[v]=arr[l];
            return seg[v];
        }
        int mid=(l+r)/2;
        return seg[v]=min(seg_init(v*2,l,mid),seg_init(v*2+1,mid+1,r));
    }
    void _init(int n,vector<ll> t)
    {
        arr.resize(n+10);
        seg.resize(n*4+10);
        for(int i=0;i<t.size();i++)
            arr[i]=t[i];
        seg_init(1,0,n-1);
    }
    void update(int v,int l,int r,int idx,ll num)
    {
        if(l>idx || r<idx) return;
        if(l==r)
        {
            seg[v]=num;
            return;
        }
        int mid=(l+r)/2;
        update(v*2,l,mid,idx,num);
        update(v*2+1,mid+1,r,idx,num);
        seg[v]=min(seg[v*2],seg[v*2+1]);
    }
    ll query(int v,int l,int r,int s,int e)
    {
        if(l>e || r<s) return 1e18;
        if(l>=s && r<=e) return seg[v];
        int mid=(l+r)/2;
        return min(query(v*2,l,mid,s,e),query(v*2+1,mid+1,r,s,e));
    }
};
struct SumSeg
{
    vector<ll> arr;
    vector<ll> seg;
    ll seg_init(int v,int l,int r)
    {
        if(l==r)
        {
            seg[v]=arr[l];
            return seg[v];
        }
        int mid=(l+r)/2;
        return seg[v]=seg_init(v*2,l,mid)+seg_init(v*2+1,mid+1,r);
    }
    void _init(int n,vector<ll> t)
    {
        arr.resize(n+10);
        seg.resize(n*4+10);
        for(int i=0;i<t.size();i++)
            arr[i]=t[i];
        seg_init(1,0,n-1);
    }
    void update(int v,int l,int r,int idx,ll num)
    {
        if(l>idx || r<idx) return;
        if(l==r)
        {
            seg[v]=num;
            return;
        }
        int mid=(l+r)/2;
        update(v*2,l,mid,idx,num);
        update(v*2+1,mid+1,r,idx,num);
        seg[v]=seg[v*2]+seg[v*2+1];
    }
    ll query(int v,int l,int r,int s,int e)
    {
        if(l>e || r<s) return 0ll;
        if(l>=s && r<=e) return seg[v];
        int mid=(l+r)/2;
        return query(v*2,l,mid,s,e)+query(v*2+1,mid+1,r,s,e);
    }
};
int n,m;
string s[3000];
int arr[2510][2510][5]; //위 아래 왼 오
int table[2510][2510];
int ch[2510][2510];
vector<pii> v1,v2;
void dfs(int y,int x)
{
    ch[y][x]=1;
    v2.push_back({y,x});
    if(table[y][x]) v1.push_back({y,x});
    if(y>0 && arr[y][x][1]==0)
        dfs(y-1,x);
    else if(x<m-1 && arr[y][x][4]==0)
        dfs(y,x+1);
}
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='G' || s[i][j]=='P')
                table[i][j]=1;
            if(s[i][j]=='G' || s[i][j]=='D')
            {
                arr[i][j][1]=arr[i][j][3]=1;
                if(i>0) arr[i-1][j][2]=1;
                if(j>0) arr[i][j-1][4]=1;
            }
            else if(s[i][j]=='Z' || s[i][j]=='P')
            {
                arr[i][j][2]=arr[i][j][4]=1;
                if(i<n-1) arr[i+1][j][1]=1;
                if(j<m-1) arr[i][j+1][3]=1;
            }
            else
            {
                arr[i][j][1]=arr[i][j][2]=arr[i][j][3]=arr[i][j][4]=1;
                if(i>0) arr[i-1][j][2]=1;
                if(j>0) arr[i][j-1][4]=1;
                if(i<n-1) arr[i+1][j][1]=1;
                if(j<m-1) arr[i][j+1][3]=1;
            }
        }
    }  
    int res_a=0,res_b=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<m;j++)
        {
            if(ch[i][j]) continue;
            dfs(i,j);
            reverse(all(v1));
            reverse(all(v2));
            int idx=0;
            for(auto i:v1)
            {
                pii a=i,b=v2[idx++];
                res_a+=a.fi-b.fi;
                res_b+=b.se-a.se;
            }
            v1.clear();
            v2.clear();
        }
    }
    if(res_b>res_a) cout<<"Scallion";
    else cout<<"Aubergine";
}
