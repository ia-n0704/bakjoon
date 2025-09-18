# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
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
int dx,dy,r_dx,r_dy,n,q;
int sum[3010][3010];
int l_sum[3010][3010];
int r_sum[3010][3010];
void init()
{
    for(int i=1;i<=3000;i++)
        for(int j=1;j<=3000;j++)
            sum[i][j]=r_sum[i][j]=l_sum[i][j]=0;
}
int main()
{
    fastio;
    int t=0;    //x,y 좌표 거꾸로 뒤집기
    while(++t)
    {
        cin>>dx>>dy>>n>>q;
        r_dx=dx,r_dy=dy;
        if(dx==0) break;
        dx+=2000;
        dy+=2000;
        for(int i=1;i<=n;i++)
        {
            int a,b;
            cin>>a>>b;
            a+=1000;
            b+=1000;
            sum[b][a]++;
            sum[b+1][a]++;
            l_sum[b][a]++;
            r_sum[b][a]++;
        }
        for(int i=1;i<=dy;i++)
        {
            for(int j=1;j<=dx;j++)
            {
                l_sum[i][j]+=l_sum[i-1][j+1];
                r_sum[i][j]+=r_sum[i-1][j-1];
            }
        }
        for(int i=1;i<=dy;i++)
        {
            sum[i][0]=sum[i-1][1];
            for(int j=1;j<=dx;j++)
            {
                sum[i][j]+=sum[i-1][j-1]+sum[i-1][j+1];
                if(i>1) sum[i][j]-=sum[i-2][j];
                //cout<<sum[i][j]<<" ";
            }
            //cout<<'\n';
        }
        /*for(int i=1001;i<=1005;i++)
        {
            for(int j=1001;j<=1005;j++)
                cout<<sum[i][j]<<" ";
            cout<<'\n';
        }*/
        cout<<"Case "<<t<<":\n";
        for(int i=1;i<=q;i++)
        {
            int m;
            cin>>m;
            int res=-1;
            int res_x,res_y;
            for(int y=1001;y<=r_dy+1000;y++)
            {
                for(int x=1001;x<=r_dx+1000;x++)
                {
                    int co=sum[y+m][x]-sum[y][x+m+1]-sum[y][x-m-1]+sum[y-m-1][x]+r_sum[y][x-m-1]+l_sum[y][x+m+1];
                    if(co>res)
                    {
                        //cout<<co<<" : "<<y<<" "<<x<<" "<<sum[y][x]<<'\n';
                        res=co;
                        res_x=x;
                        res_y=y;
                    }
                }
            }
            cout<<res<<" "<<"("<<res_x-1000<<","<<res_y-1000<<")\n";
        }
        init();
    }
}
