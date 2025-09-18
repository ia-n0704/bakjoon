#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
ll arr[1000005];

struct TREE{
    ll node=0;
    ll lazy=0;
}tree[4000005];

ll build(ll idx,ll st,ll ed)
{
    ll mid = (st+ed)/2;
    if(st==ed) 
    {
        tree[idx].node=arr[st];
        return tree[idx].node;
    }
    build(idx*2,st,mid);
    build(idx*2+1,mid+1,ed);
    return tree[idx].node = tree[idx*2].node+tree[idx*2+1].node;
}
ll query1(ll idx,ll nst,ll ned,ll st,ll ed,ll num)
{
    if(tree[idx].lazy!=0)
    {
        tree[idx].node += (ned-nst+1)*tree[idx].lazy;
        if(nst!=ned)
        {
            tree[idx*2].lazy += tree[idx].lazy;
            tree[idx*2+1].lazy += tree[idx].lazy;
        }
        tree[idx].lazy = 0;
    }
    ll mid = (nst+ned)/2;
    if(nst>ed||ned<st) return tree[idx].node;
    if(nst>=st&&ned<=ed)
    {
        tree[idx].node += (ned-nst+1)*num;
        if(nst!=ned)
        {
            tree[idx*2].lazy += num;
            tree[idx*2+1].lazy += num;
        }
        return tree[idx].node;
    }
    return tree[idx].node=query1(idx*2,nst,mid,st,ed,num)+query1(idx*2+1,mid+1,ned,st,ed,num);
}
ll query2(ll idx,ll nst,ll ned,ll st,ll ed) //tree[idx]는 nst부터 ned까지의 합을 저장한 노드
{
    if(tree[idx].lazy!=0)
    {
        tree[idx].node += (ned-nst+1)*tree[idx].lazy;
        if(nst!=ned)
        {
            tree[idx*2].lazy += tree[idx].lazy;
            tree[idx*2+1].lazy += tree[idx].lazy;
        }
        tree[idx].lazy = 0;
    }
    ll mid = (nst+ned)/2;
    if(nst>ed||ned<st) return 0;
    if(nst>=st&&ned<=ed) return tree[idx].node;

    ll l = query2(idx*2,nst,mid,st,ed);
    ll r = query2(idx*2+1,mid+1,ned,st,ed);
    return l+r;
}
void print(int node,int l,int r)
{
    //cout<<node<<" "<<l<<" "<<r<<" | "<<tree[node].node<<'\n';
    if(l==r)
        return;
    int mid=(l+r)/2;
    print(node*2,l,mid);
    print(node*2+1,mid+1,r);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++)cin>>arr[i];
    build(1,1,n);
    //cout<<query2(1,1,n,1,2)<<'\n';
    //print(1,1,n);
    //cout<<'\n';
    for(ll i=1;i<=m+k;i++)
    {
        ll temp,a,b,c;
        cin>>temp;
        if(temp==1)
        {
            cin>>a>>b>>c;
            query1(1,1,n,a,b,c);
        }
        if(temp==2)
        {
            cin>>a>>b;
            cout<<query2(1,1,n,a,b)<<"\n";
        }
        //print(1,1,n);
    }
}