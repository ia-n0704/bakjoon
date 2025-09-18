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
int arr[100010];
pair<int,int> seg[400040];
int q;
void update(int v,int l,int r,int idx,int num)
{
    if(l>idx || r<idx) return;
    if(l==r)
    {
        if(num%2) seg[v]={0,1};
        else seg[v]={1,0};
        return;
    }
    int mid=(l+r)/2;
    update(v*2,l,mid,idx,num);
    update(v*2+1,mid+1,r,idx,num);
    seg[v]={seg[v*2].first+seg[v*2+1].first,seg[v*2].second+seg[v*2+1].second};
}
pair<int,int> query(int v,int l,int r,int s,int e)
{
    if(l>e || r<s) return {0,0};
    if(l>=s && r<=e) return seg[v];
    int mid=(l+r)/2;
    auto a=query(v*2,l,mid,s,e);
    auto b=query(v*2+1,mid+1,r,s,e);
    return {a.first+b.first,a.second+b.second};
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        update(1,1,n,i,arr[i]);
    }
    cin>>q;
    while(q--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
            update(1,1,n,b,c);
        auto res=query(1,1,n,b,c);
        if(a==2) cout<<res.first<<'\n';
        if(a==3) cout<<res.second<<'\n';
    }
}