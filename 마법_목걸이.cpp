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
ll arr[200010];
ll near[400010][20];
ll seg[1600040];
ll gcd(ll a,ll b)
{
    while(b)
    {
        ll r=a%b;
        a=b;
        b=r;
    }
    return a;
}
void update(int v,int l,int r,int idx,ll num)
{
    if(idx<l || idx>r) return;
    if(l==r) 
    {
        seg[v]=num;
        return;
    }
    int mid=(l+r)/2;
    update(v*2,l,mid,idx,num);
    update(v*2+1,mid+1,r,idx,num);
    seg[v]=gcd(seg[v*2],seg[v*2+1]);
}
ll query(int v,int l,int r,int s,int e)
{
    if(l>e || r<s) return -1;
    if(s<=l && e>=r) return seg[v];
    int mid=(l+r)/2;
    ll a=query(v*2,l,mid,s,e),b=query(v*2+1,mid+1,r,s,e);
    if(a==-1) return b;
    else if(b==-1) return a;
    else return gcd(a,b);
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        update(1,1,n*2,i,arr[i]);
        update(1,1,n*2,n+i,arr[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int l=i,r=n+i-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(query(1,1,n*2,i,mid)==1)
                r=mid-1;
            else l=mid+1; 
        }
        if(l==n+i) near[i][0]=-1;
        else if(r==i-1) near[i][0]=i;
        else near[i][0]=l;
        near[n+i][0]=near[i][0]+n;
        if(near[n+i][0]>n*2) near[n+i][0]=-1;
        //cout<<near[i][0]<<" ";
    }
    for(int j=1;j<=18;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(near[i][j-1]==-1 || near[i][j-1]+1>=n+i) near[i][j]=-1;
            else near[i][j]=near[near[i][j-1]+1][j-1];
            if(near[i][j]>=n+i) near[i][j]=-1;

            if(near[i][j]==-1) near[n+i][j]=-1;
            else near[n+i][j]=near[i][j]+n;

            if(near[n+i][j]>2*n) near[n+i][j]=-1;
            //cout<<near[i][j]<<" ";
        }
    }
    for(int i=1;i<=n;i++)
    {
        ll res=0;
        int cur=i;
        for(ll j=18;j>=0;j--)
        {
            if(cur>=n+i) break;
            if(near[cur][j]!=-1 && near[cur][j]<n+i)
            {
                cur=near[cur][j]+1;
                res+=(ll)(1<<j);
            }
        }
        cout<<res<<'\n';
    }
}