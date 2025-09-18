# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
pll arr[200010];
int ch[200010];
int seg[1600010];
void update(int v,int l,int r,int idx)
{
    if(idx<l || idx>r) return;
    if(l==r)
    {
        seg[v]++;
        return;
    }
    int mid=(l+r)/2;
    update(v*2,l,mid,idx);
    update(v*2+1,mid+1,r,idx);
    seg[v]=min(seg[v*2],seg[v*2+1]);
}
int query(int v,int l,int r,int s,int e)
{
    if(l>e || r<s) return 2;
    if(l>=s && r<=e) return seg[v];
    int mid=(l+r)/2;
    return min(query(v*2,l,mid,s,e),query(v*2+1,mid+1,r,s,e));
}
void sol()
{
    map<pll,int> m;
    cin>>n;
    fill(ch,ch+n+1,0);
    fill(seg,seg+n*8+5,0);
    for(int i=1;i<=n;i++) cin>>arr[i].fi>>arr[i].se;
    for(int i=1;i<=n;i++)
    {
        if(arr[i].fi==arr[i].se)
            update(1,1,2*n,arr[i].fi);
    }
    for(int i=1;i<=n;i++)
    {
        int num=query(1,1,2*n,arr[i].fi,arr[i].se);
        //cout<<num<<'\n';
        if(arr[i].fi==arr[i].se)
        {
            if(num>1) ch[i]=1;
        }
        else if(num>0) ch[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<(ch[i]^1);
    }
    cout<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}