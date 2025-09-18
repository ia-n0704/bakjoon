# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct seg
{
    ll mx,sum;
};
int n;
seg tree[4040404];
ll ans;
vector<pair<ll,ll>> v;
void merge(int a)
{
    tree[a].sum=tree[a*2].sum+tree[a*2+1].sum;
    tree[a].mx=max(tree[a*2+1].mx,tree[a*2].mx+tree[a*2+1].sum);
    return;
}
void init(int a,int st,int en)
{
    if(st==en)
    {
        tree[a].mx=st;
        tree[a].sum=0;
        return;
    }
    int mid=(st+en)/2;
    init(a*2,st,mid);
    init(a*2+1,mid+1,en);
    merge(a);
}
void update(int a,int st,int en,ll x,ll d)
{
    if(st==en)
    {
        tree[a].sum+=d;
        tree[a].mx+=d;
        return;
    }
    int mid=(st+en)/2;
    if(mid>=x) update(a*2,st,mid,x,d);
    else update(a*2+1,mid+1,en,x,d);
    merge(a);
}
void query(int a,int st,int en,int x)
{
    if(en<=x)
    {
        ans=max(ans+tree[a].sum,tree[a].mx);
        return;
    }
    int mid=(st+en)/2;
    query(a*2,st,mid,x);
    if(mid<x)
        query(a*2+1,mid+1,en,x);
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    v.resize(n+1);
    init(1,1,1000000);
    for(int i=1;i<=n;i++)
    {
        char s;
        cin>>s;
        if(s=='+')
        {
            ll a,b;
            cin>>a>>b;
            v[i]={a,b};
            update(1,1,1000000,a,b);
        }
        else if(s=='-')
        {
            ll a;
            cin>>a;
            update(1,1,1000000,v[a].first,-v[a].second);
        }
        else
        {
            ll a;
            cin>>a;
            ans=0;
            query(1,1,1000000,a);
            cout<<max(ans-a,0ll)<<'\n';
        }
    }
}