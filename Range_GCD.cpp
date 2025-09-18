#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;
typedef long long ll;
int n,q;
ll arr[100010];
ll gcd(ll a, ll b){
	while(b!=0){
		ll r = a%b;
		a= b;
		b= r;
	}
	return a;
}
struct LazySeg
{
    ll tree[400010]={0};
    ll lazy[400010]={0};
    void init(int v,int l,int r)
    {
        if(l==r)
        {
            tree[v]=arr[l];
            return;
        }
        int mid=(l+r)/2;
        init(v*2,l,mid);
        init(v*2+1,mid+1,r);
        tree[v]=tree[v*2]+tree[v*2+1];
        //cout<<v <<" | "<<tree[v]<<'\n';
    }
    void prop(int v,int l,int r)
    {
        if(!lazy[v]) return;
        tree[v]+=lazy[v]; 
        if(l!=r)
        {
            for(int i=v*2;i<=v*2+1;i++)
            {
                lazy[i]+=lazy[v];
            }            
        }
        lazy[v]=0;
    }
    ll query(int v,int l,int r,int s)
    {
        prop(v,l,r);
        if(l>s || r<s)
            return 0;        
        if(l==r)
            return tree[v]; 
        int mid=(l+r)/2;
        return query(v*2,l,mid,s)+query(v*2+1,mid+1,r,s);
    }
    void update(int v,int l,int r,int s,int e,int a)
    {
        prop(v,l,r);
        if(l>e || r<s)
            return;
        if(l>=s && r<=e)
        {
            lazy[v]=a;
            prop(v,l,r);
            return;
        }
        int mid=(l+r)/2;
        update(v*2,l,mid,s,e,a);
        update(v*2+1,mid+1,r,s,e,a);
        tree[v]=tree[v*2]+tree[v*2+1];
    }
}SUM;
ll brr[400010];
struct Seg
{
    ll tree[400010]={0};
    void init(int v,int l,int r)
    {
        if(l==r)
        {
            tree[v]=brr[l];
            return;
        }
        int mid=(l+r)/2;
        init(v*2,l,mid);
        init(v*2+1,mid+1,r);
        tree[v]=gcd(tree[v*2],tree[v*2+1]);
        //cout<<tree[v]<<" ";
    }
    void update(int v,int l,int r,int idx,int x)
    {
        if(l>idx || r<idx)
            return;
        if(l==r)
        {
            tree[v]+=x;
            return;
        }
        int mid=(l+r)/2;
        update(v*2,l,mid,idx,x);
        update(v*2+1,mid+1,r,idx,x);
        tree[v]=gcd(tree[v*2],tree[v*2+1]);
    }
    ll query(int v,int l,int r,int s,int e)
    {
        if(l>e || r<s)
            return 0;
        if(l>=s && r<=e)
            return tree[v];
        int mid=(l+r)/2;
        return gcd(query(v*2,l,mid,s,e),query(v*2+1,mid+1,r,s,e));
    }
}GCD;
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=2;i<=n;i++) brr[i-1]=arr[i]-arr[i-1];
    SUM.init(1,1,n);
    GCD.init(1,1,n);
    cin>>q;
    while(q--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0)
        {
            cout<<abs(gcd(SUM.query(1,1,n,b),GCD.query(1,1,n,b,c-1)))<<'\n';
            //cout<<SUM.query(1,1,n,b)<<" "<<GCD.query(1,1,n,b,c-1)<<'\n';
        }
            
        else
        {
            SUM.update(1,1,n,b,c,a);
            GCD.update(1,1,n,b-1,a);
            GCD.update(1,1,n,c,-a);
        }
    }
}

