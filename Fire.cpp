# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,q;
ll s[200010];
bool comp(Query a,Query b)
{
    return a.t>b.t;
}
struct Query
{
    int t,l,r;
}arr[200010];
ll seg[800040];
ll init(int node,int l,int r)
{
    if(l==r)
        return seg[node]=arr[l];
    int mid=(l+r)/2;
    return seg[node]=init(node*2,l,mid)+init(node*2+1,mid+1,r);
}
void update(int node,int l,int r,int x,int d)
{

}
int main()
{
    fastio;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=q;i++)
        cin>>arr[i].t>>arr[i].l>>arr[i].r;
    sort(arr+1,arr+q+1,comp);
    int idx=1;
    for(int i=1;i<=n;i++)
    {
        
    }
}