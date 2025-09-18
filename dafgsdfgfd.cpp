# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int seg[1000010];
int arr[200010],brr[200010];
void init(int v,int l,int r)
{
    if(l==r)
    {
        seg[v]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    init(v*2,l,mid);
    init(v*2+1,mid+1,r);
    seg[v]=seg[v*2]+seg[v*2+1];
}
int query(int v,int l,int r,int s,int e)
{
    if(s>r || e<l) return 0;
    if(l>=s && r<=e) return seg[v];
    int mid=(l+r)/2;
    return query(v*2,l,mid,s,e)+query(v*2+1,mid+1,r,s,e);
}
void sol()
{
    int n,q;
    cin>>n;
    string s,t;
    cin>>s>>t;
    for(int i=1;i<=n;i++) arr[i]=s[i-1]-'0';
    for(int i=1;i<=n;i++) brr[i]=t[i-1]-'0';
    for(int i=2;i<=n-1;i++)
        if(!arr[i-1] && !arr[i+1]) brr[i]=1;
    for(int i=2;i<=n-1;i++)
        if(brr[i-1] && brr[i+1]) arr[i]=1;
    init(1,1,n);
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(1,1,n,l,r)<<'\n';
    }
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