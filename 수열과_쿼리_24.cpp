# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m;
int arr[100010];
pair<int,int> tree[400010];
pair<int,int> merge(pair<int,int> x,pair<int,int> y)
{
    if(x.first>y.first)
        return {x.first,max(x.second,y.first)};
    else return {y.first,max(x.first,y.second)};
}
void init(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]={arr[l],0};
        return;
    }
    int mid=(l+r)/2;
    init(node*2,l,mid);
    init(node*2+1,mid+1,r);
    tree[node]=merge(tree[node*2],tree[node*2+1]);
}
void update(int node,int l,int r,int x,int d)
{
    if(x>r || x<l)
        return;
    if(l==r && l==x)
    {
        tree[node]={d,0};
        return;
    }
    int mid=(l+r)/2;
    update(node*2,l,mid,x,d);
    update(node*2+1,mid+1,r,x,d);
    tree[node]=merge(tree[node*2],tree[node*2+1]);
}
pair<int,int> res;
void query(int node,int l,int r,int st,int en)
{
    if(st>r || en<l)
        return;
    if(st<=l && en>=r)
    {
        res=merge(res,tree[node]);
        return;
    }
    int mid=(l+r)/2;
    query(node*2,l,mid,st,en),query(node*2+1,mid+1,r,st,en);
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    init(1,1,n);
    cin>>m;
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
            update(1,1,n,b,c);
        else
        {
            query(1,1,n,b,c);
            cout<<res.first+res.second<<'\n';
            res={0,0};
        }
    }
}