# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll inf=1e18;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,q;
ll arr[200010];
struct Seg
{
    ll mn,mx,sum;
}tree[800010];
ll lazyone[800010];
ll lazytwo[800010];
Seg f(Seg x,Seg y)
{
    return {min(x.mn,y.mn),max(x.mx,y.mx),x.sum+y.sum};
}
void prop(int v,int s,int e)
{
    if(lazytwo[v]<=-inf)
    {
        tree[v].mx+=lazyone[v];
        tree[v].mn+=lazyone[v];
        tree[v].sum+=(e-s+1)*lazyone[v];
        //cout<<(e-s+1)*lazyone[v]<<'\n';
        if(s!=e)
        {
            for(auto i:{v*2,v*2+1})
                lazyone[i]+=lazyone[v];
        }
    }
    else
    {
        tree[v].mx=lazyone[v]+lazytwo[v];
        tree[v].mn=lazyone[v]+lazytwo[v];
        tree[v].sum=(e-s+1)*(lazyone[v]+lazytwo[v]);
        if(s!=e)
        {
            for(auto i:{v*2,v*2+1})
            {
                lazyone[i]=lazyone[v];
                lazytwo[i]=lazytwo[v];
            }
        }
    }
    lazyone[v]=0;
    lazytwo[v]=-inf;
}
void init(int v,int s,int e)
{
    if(s==e)
    {
        tree[v]={arr[s],arr[s],arr[s]};
        return;
    }
    int mid=(s+e)/2;
    init(v*2,s,mid);
    init(v*2+1,mid+1,e);
    tree[v]=f(tree[v*2],tree[v*2+1]);
}
void add(int v,int s,int e,int l,int r,ll d)
{
    prop(v,s,e);
    if(s>r || e<l)
        return;
    if(s>=l && e<=r)
    {
        lazyone[v]=d;
        prop(v,s,e);
        //cout<<tree[v].sum<<'\n';
        return;
    }
    int mid=(s+e)/2;
    add(v*2,s,mid,l,r,d);
    add(v*2+1,mid+1,e,l,r,d);
    tree[v]=f(tree[v*2],tree[v*2+1]);
}
void div(int v,int s,int e,int l,int r,ll d)
{
    prop(v,s,e);
    if(s>r || e<l)
        return;
    if(s>=l && e<=r)
    {
        if(floor((double)tree[v].mn/d)==floor((double)tree[v].mx/d))
        {
            lazytwo[v]=floor((double)tree[v].mn/d);
            prop(v,s,e);
            return;
        }
        if(tree[v].mn+1==tree[v].mx)
        {
            lazyone[v]=floor((double)tree[v].mn/d)-tree[v].mn;
            prop(v,s,e);
            return;
        }
    }
    int mid=(s+e)/2;
    div(v*2,s,mid,l,r,d);
    div(v*2+1,mid+1,e,l,r,d);
    tree[v]=f(tree[v*2],tree[v*2+1]);
}
Seg query(int v,int s,int e,int l,int r)
{
    prop(v,s,e);
    if(s>r || e<l)
        return {inf,-inf,0};
    if(s>=l && e<=r)
        return tree[v];
    int mid=(s+e)/2;
    return f(query(v*2,s,mid,l,r),query(v*2+1,mid+1,e,l,r));
}
int main()
{
    fastio;
    fill(lazytwo,lazytwo+600005,-inf);
    cin>>n>>q;
    for(int i=1;i<=n;i++) 
        cin>>arr[i];
    init(1,1,n);
    while(q--)
    {
        int c;
        cin>>c;
        ll x,y,z;
        if(c==0)
        {
            cin>>x>>y>>z;
            add(1,1,n,x+1,y+1,z);
        }
        else if(c==1)
        {
            cin>>x>>y>>z;
            div(1,1,n,x+1,y+1,z);
        }
        else if(c==2)
        {
            cin>>x>>y>>z;
            Seg res=query(1,1,n,x+1,y+1);
            cout<<res.mx<<'\n';
        }
    }
}