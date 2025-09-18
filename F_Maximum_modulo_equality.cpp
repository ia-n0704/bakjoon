# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
int arr[200010];
int seg[800010];
int num[200010];
void update(int v,int l,int r,int idx,int x)
{
    if(idx<l || idx>r) return;
    if(l==r)
    {
        seg[v]=x;
        return;
    }
    int mid=(l+r)/2;
    update(v*2,l,mid,idx,x);
    update(v*2+1,mid+1,r,idx,x);
    seg[v]=__gcd(seg[v*2],seg[v*2+1]);
}
int query(int v,int l,int r,int s,int e)
{
    if(l>e || r<s) return 0;
    //cout<<v<<" | "<<l<<" "<<r<<'\n';;
    if(l>=s && r<=e)
        return seg[v];
    int mid=(l+r)/2;
    int a=query(v*2,l,mid,s,e);
    int b=query(v*2+1,mid+1,r,s,e);
    int res=0;
    if(a!=0) res=a;
    if(res!=0 && b!=0) res=__gcd(res,b);
    else if(b!=0) res=b; 
    return res;
}
void sol()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<n;i++)
        update(1,1,n,i,abs(arr[i]-arr[i+1]));
    for(int i=1;i<=q;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<query(1,1,n,a,b-1)<<' ';
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