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
ll n,m;
ll arr[500010],brr[500010];
ll a[500010],b[500010];
ll ah[500010],bh[500010];
ll res;
pll sa[500010],sb[500010];
int main()
{
    fastio;
    cin>>n>>m;
    n++,m++;

    for(int i=n;i>=1;i--)
    {
        cin>>arr[i];
        if(i<n)
        {
            a[i]=arr[i+1]-arr[i];
            ah[i]=1;
        }
    }
    res+=arr[1]*(m-1);
    for(int i=1;i<=m;i++)
    {
        cin>>brr[i];
        if(i>1)
        {
            bh[i-1]=1;
            b[i-1]=brr[i]-brr[i-1];
            //cout<<b[i-1]<<" ";
        }
    }
    //cout<<'\n';
    res+=brr[1]*(n-1);

    vector<pll> va,vb;
    for(int i=1;i<=n-1;i++)
    {
        ll x=a[i];
        ll y=1;
        /*while(!va.empty())
        {
            pll temp=va.back();
            if(temp.fi>=x)
            {
                va.pop_back();
                x+=temp.fi;
                y+=temp.se;
            }
            else break;
        }*/
        va.push_back({x,y});
    }
    //for(auto i:va) cout<<i.fi<<' ';

    for(ll i=1;i<=m-1;i++)
    {
        ll x=b[i];
        ll y=1;
        /*while(!vb.empty())
        {
            pll temp=vb.back();
            if(temp.fi>=x)
            {
                //cout<<"| "<<temp.fi<<" "<<x<<'\n';
                vb.pop_back();
                x+=temp.fi;
                y+=temp.se;
            }
            else break;
        }*/
        vb.push_back({x,y});
    }
    /*cout<<'\n';
    for(auto i:vb) cout<<i.fi<<" "<<i.se<<' ';
    cout<<'\n';*/

    vector<pll> vva,vvb;
    vva.push_back(va.front());
    vvb.push_back(vb.front());
    for(ll j=1;j<va.size();j++)
    {
        pll i=va[j];
        while(!vva.empty())
        {
            pll temp=vva.back();
            if(i.fi*temp.se<=i.se*temp.fi)
            {
                i.fi+=temp.fi;
                i.se+=temp.se;
                vva.pop_back();
            }
            else break;
        }
        vva.push_back(i);
    }
    for(ll j=1;j<vb.size();j++)
    {
        pll i=vb[j];
        while(!vvb.empty())
        {
            pll temp=vvb.back();
            if(i.fi*temp.se<=i.se*temp.fi)
            {
                i.fi+=temp.fi;
                i.se+=temp.se;
                vvb.pop_back();
            }
            else break;
        }
        vvb.push_back(i);
    }
    /*cout<<'\n';
    for(auto i:vva) cout<<i.fi<<" "<<i.se<<"\n";
    cout<<'\n'<<'\n';
    for(auto i:vvb) cout<<i.fi<<" "<<i.se<<"\n";
    cout<<'\n';*/

    sa[0]=vva[0];
    for(ll i=1;i<vva.size();i++)
    {
        sa[i].fi=sa[i-1].fi+vva[i].fi;
        sa[i].se=sa[i-1].se+vva[i].se;
    }
    sb[0]=vvb[0];
    for(ll i=1;i<vvb.size();i++)
    {
        sb[i].fi=sb[i-1].fi+vvb[i].fi;
        sb[i].se=sb[i-1].se+vvb[i].se;
    }
    //cout<<res<<'\n';
    ll idx=vva.size()-1;
    for(ll i=0;i<vvb.size();i++)
    {
        while(idx>=0 && vva[idx].fi*vvb[i].se+vva[idx].se*vvb[i].fi>0)
            idx--;
        //cout<<idx<<" "<<vvb[i].se<<" "<<res<<" "<<'\n';
        if(idx!=-1)
            res+=sa[idx].fi*vvb[i].se+sa[idx].se*vvb[i].fi;
    }
    cout<<res;
}