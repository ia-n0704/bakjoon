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
        if(l>e || r<s) return 1e9;
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
int n,m,p;
pair<pii,int> road[300010];
vector<pii> v[300010];
int ans[300010];
int ch[300010];
map<int,int> M;
bool compare(pii a,pii b)
{
    return a.se<b.se;
}
int main()
{
    fastio;
    cin>>n>>m>>p;
    vector<int> temp;
    for(int i=1;i<=m;i++)
    {
        cin>>road[i].fi.fi>>road[i].fi.se>>road[i].se;
        temp.push_back(road[i].se);
    }
    sort(all(temp));
    temp.erase(unique(all(temp)),temp.end());
    int sz=temp.size();
    for(int i=1;i<=temp.size();i++)
        M[temp[i-1]]=i;
    for(int i=1;i<=m;i++)
        v[M[road[i].se]].push_back(road[i].fi);
    
    int st=1,cnt=1;
    for(int i=1;i<=sz;i++)
    {
        for(auto k:v[i])
        {
            if(k.se==1) continue;
            if(ch[k.se]==0)
                cnt++;
            ch[k.se]++;
        }
        if(cnt>=n)
        {
            st=i;
            break;
        }
    }
    if(cnt<n)
    {
        int q;
        cin>>q;
        for(int i=1;i<=q;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            cout<<"No\n";
        }
        return 0;
    }
    ans[1]=st;
    for(int i=2;i<=sz;i++)
    {
        for(auto j:v[i-1])
        {
            ch[j.se]--;
            if(ch[j.se]==0) cnt--;
        }
        while(st<sz && cnt<n)
        {
            st++;
            for(auto j:v[st])
            {
                if(ch[j.se]==0) cnt++;
                ch[j.se]++;
            }
        }
        ans[i]=st;
        if(cnt<n) ans[i]=-1;
    }
    //가능한 구간을 압축한거 복구해서 오름차순으로 만든뒤에 세그에 구간의 길이에 대한 min을 관리하도록 만듦.
    //그 구간을 a-x랑 b+x에 대한 lowerbound, upperbound-1 로 이분탐색 후 구간으로 쿼리 돌리면 됨.
    vector<pii> range;
    for(int i=1;i<=sz;i++)
    {
        if(ans[i]!=-1)
        {
            //cout<<temp[i-1]<<" "<<temp[ans[i]-1]<<'\n';
            range.push_back({temp[i-1],temp[ans[i]-1]});
        }
    }
    MinSeg Seg;
    Seg._init(sz,{});
    for(int i=0;i<range.size();i++)
        Seg.update(1,0,sz,i,range[i].se-range[i].fi+1);

    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int l=lower_bound(all(range),make_pair(a-c,-1))-range.begin();
        int r=upper_bound(all(range),make_pair(-1,b+c),compare)-range.begin();
        //cout<<l<<" "<<r<<' ';
        int num=Seg.query(1,0,sz,l,r-1);
        //cout<<num<<" ";
        if(num<=b-a+c+1) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
