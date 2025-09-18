# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
int arr[500010];
pair<int,int> brr[500010];
int seg[2000010];
void update(int v,int l,int r,int idx,int num)
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
int query(int v,int l,int r,int s,int e)
{
    if(s>r || e<l) return 0;
    if(s<=l && e>=r) return seg[v];
    int mid=(l+r)/2;
    return query(v*2,l,mid,s,e)+query(v*2+1,mid+1,r,s,e);
}
int main()
{
    fastio;
    cin>>n;
    long long res=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        brr[i]={arr[i],i};
        update(1,1,n,i,1);
    }
    sort(brr+1,brr+n+1);
    for(int i=1;i<=n;i++)
    {
        res+=(ll)query(1,1,n,1,brr[i].second-1);
        update(1,1,n,brr[i].second,0);
    }
    cout<<res;
}  