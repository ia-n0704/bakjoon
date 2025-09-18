#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll seg[400040],lazy[400010][2],arr[100010];
ll n,q;
void go(int v,int st,int en)
{
    if(st==en) 
    {
        seg[v]=arr[st];
        return;
    }
    int mid=(st+en)/2;
    go(v*2,st,mid);
    go(v*2+1,mid+1,en);
    seg[v]=(seg[v*2]+seg[v*2+1])%mod;
}
void update(int v,int l,int r)
{
    //cout<<v<<" "<<l<<" "<<r<<" "<<lazy[v][0]<<" "<<lazy[v][1]<<'\n';
    if(lazy[v][0]==1 && lazy[v][1]==0)
        return;
    lazy[v][0]%=mod;
    lazy[v][1]%=mod;
    if(l!=r)
    {
        for(int i=v*2;i<=v*2+1;i++)
        {
            lazy[i][0]*=lazy[v][0];
            lazy[i][1]=lazy[i][1]*lazy[v][0]+lazy[v][1];
            lazy[i][0]%=mod;
            lazy[i][1]%=mod;       
        }
    }
    seg[v]=(seg[v]*lazy[v][0]+(r-l+1)*lazy[v][1])%mod;
    lazy[v][0]=1;
    lazy[v][1]=0;
}
void query(int v,int st,int en,int l,int r,int a,int b)
{
    update(v,st,en);
    if(l>en || r<st)
        return;
    if(l<=st && r>=en)
    {
        lazy[v][0]*=a;
        lazy[v][1]=lazy[v][1]*a+b;
        update(v,st,en);
        return;
    }
    int mid=(st+en)/2;
    query(v*2,st,mid,l,r,a,b);
    query(v*2+1,mid+1,en,l,r,a,b);
    seg[v]=(seg[v*2]+seg[v*2+1])%mod;
}
ll f(int v,int st,int en,int l,int r)
{
    update(v,st,en);
    //cout<<st<<" "<<en<<" "<<l<<" "<<r<<'\n';
    if(st>r || en<l)
        return 0;
    if(st>=l && en<=r)
        return seg[v];
    int mid=(st+en)/2;
    return f(v*2,st,mid,l,r)+f(v*2+1,mid+1,en,l,r);
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0;i<=400005;i++) lazy[i][0]=1;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    go(1,1,n);
    cin>>q;
    while(q--)
    {
        int a;
        cin>>a;
        int x,y,c;
        if(a==1)
        {
            cin>>x>>y>>c;
            query(1,1,n,x,y,1,c);
        }
        else if(a==2)
        {
            cin>>x>>y>>c;
            query(1,1,n,x,y,c,0);
        }
        else if(a==3)
        {
            cin>>x>>y>>c;
            query(1,1,n,x,y,0,c);
        }
        else
        {
            cin>>x>>y;
            cout<<f(1,1,n,x,y)%mod<<'\n';
        }
    }
}