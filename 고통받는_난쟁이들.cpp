# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
const int mx=1e9;
int n,q;
int arr[200010];
int loc[200010];
pair<int,int> seg[800010];
void update(int v,int l,int r,int idx,int x)
{
    if(l>idx || r<idx)
        return;
    else if(l==r)
    {
        seg[v]={x,x};
        return;
    }
    int mid=(l+r)/2;
    update(v*2,l,mid,idx,x);
    update(v*2+1,mid+1,r,idx,x);
    seg[v]={min(seg[v*2].first,seg[v*2+1].first),max(seg[v*2].second,seg[v*2+1].second)};
}
pair<int,int> query(int v,int l,int r,int st,int en)
{
    if(l>en || r<st) return {mx,-mx};
    else if(l>=st && r<=en) return seg[v];
    int mid=(l+r)/2;
    auto a=query(v*2,l,mid,st,en);
    auto b=query(v*2+1,mid+1,r,st,en);
    return {min(a.first,b.first),max(a.second,b.second)};
}
int main()
{
    fastio;
    cin>>n>>q;
    for(int i=1;i<=n;i++) 
    {
        cin>>arr[i];
        loc[arr[i]]=i;
        update(1,1,n,arr[i],i);
    }
    while(q--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            update(1,1,n,arr[b],c);
            update(1,1,n,arr[c],b);
            swap(arr[b],arr[c]);
            swap(loc[b],loc[c]);
        }
        else
        {
            auto res=query(1,1,n,b,c);
            //cout<<res.first<<" "<<res.second<<'\n';
            if(res.second-res.first==max(b,c)-min(b,c))
                cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}