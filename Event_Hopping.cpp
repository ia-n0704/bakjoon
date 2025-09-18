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
const ll inf=1e9;
ll n,q;
pll arr[400010];
map<ll,ll> m;
ll table[400010][25];
pll seg[1000010];
ll mx[400010];
ll sz;
void init(ll v,ll l,ll r)
{
    seg[v]={inf,0};
    if(l==r) return;
    ll mid=(l+r)/2;
    init(v*2,l,mid);
    init(v*2+1,mid+1,r);
}
void update(ll v,ll l,ll r,ll idx,ll num,ll x)
{
    if(idx<l || idx>r) return;
    if(l==r) 
    {
        seg[v]=min(seg[v],{num,x});
        return;
    }
    ll mid=(l+r)/2;
    update(v*2,l,mid,idx,num,x);
    update(v*2+1,mid+1,r,idx,num,x);
    seg[v]=min(seg[v*2],seg[v*2+1]);
}
pll query(ll v,ll l,ll r,ll s,ll e)
{
    if(l>e || r<s) return {inf,0};
    if(l>=s && r<=e) return seg[v];
    ll mid=(l+r)/2;
    return min(query(v*2,l,mid,s,e),query(v*2+1,mid+1,r,s,e));
}
int main()
{
    fastio;
    cin>>n>>q;
    vector<ll> v;
    for(ll i=1;i<=n;i++)
    {
        cin>>arr[i].fi>>arr[i].se;
        v.push_back(arr[i].fi);
        v.push_back(arr[i].se);
    }
    sort(all(v));
    v.erase(unique(all(v)),v.end());
    for(ll i=0;i<v.size();i++)
        m[v[i]]=i+1;
    sz=v.size();
    for(ll i=1;i<=n;i++)
        arr[i]={m[arr[i].fi],m[arr[i].se]};

    init(1,1,sz);
    for(ll i=1;i<=n;i++)
        update(1,1,sz,arr[i].se,arr[i].fi,i);
    
    for(ll i=1;i<=n;i++)
    {
        table[i][0]=query(1,1,sz,arr[i].fi,arr[i].se).se;
        //cout<<table[i][0]<<" ";
    }
    for(ll i=1;i<=22;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            table[j][i]=table[table[j][i-1]][i-1];
        }
    }
    
    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        if(a==b)
        {
            cout<<0<<'\n';
            continue;
        }
        if(arr[a].se>arr[b].se)
        {
            cout<<"impossible\n";
            continue;
        }
        if(arr[a].se>=arr[b].fi)
        {
            cout<<"1\n";
            continue;
        }
        ll res=0;
        ll num=b;
        for(ll i=22;i>=0;i--)
        {
            ll nx=table[num][i];
            if(arr[nx].fi>arr[a].se)
            {
                num=nx;
                res+=(1<<i);
            }
            //cout<<i<<" "<<num<<'\n';
        }
        if(arr[num].fi>arr[a].se) res++, num=table[num][0];
        if(arr[num].fi>arr[a].se) cout << "impossible\n";
        else cout << res + 1 << '\n';
    }
}