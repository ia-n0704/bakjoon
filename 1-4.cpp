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
int n;
int seg[400010];
pair<pii,int> arr[100010];
void update(int v,int l,int r,int idx,int x)
{
    if(l>idx || r<idx) return;
    if(l==r)
    {
        seg[v]=x;
        return;
    }
    int mid=(l+r)/2;
    update(v*2,l,mid,idx,x);
    update(v*2+1,mid+1,r,idx,x);
    seg[v]=max(seg[v*2],seg[v*2+1]);
}
int query(int v,int l,int r,int s,int e)
{
    if(l>e || r<s) return 0;
    if(l>=s && r<=e) return seg[v];
    int mid=(l+r)/2;
    return max(query(v*2,l,mid,s,e),query(v*2+1,mid+1,r,s,e));
}
bool compare(pair<pii,int> a,pair<pii,int> b)
{
    pii x=a.fi,y=b.fi;
    if(x.fi<=y.fi && x.se>=y.se) return 0;
    if(y.fi<=x.fi && y.se>=x.se) return 1;
    if(x.se<y.fi || y.se<x.fi)
        return query(1,1,n,x.fi,x.se)<query(1,1,n,y.fi,y.se);
    if(x.fi<y.fi)
        return query(1,1,n,x.fi,y.fi-1)<query(1,1,n,x.se+1,y.se);
    return query(1,1,n,y.se+1,x.se)<query(1,1,n,y.fi,x.fi-1);
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        update(1,1,n,i,a);
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>arr[i].fi.fi>>arr[i].fi.se;
        arr[i].se=i;
    }
    sort(arr+1,arr+q+1,compare);
    for(int i=1;i<=q;i++)
        cout<<arr[i].se<<" ";
}
