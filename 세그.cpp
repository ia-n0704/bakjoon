#include <bits/stdc++.h>
using namespace std;
int tree[400010];
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
}
void update(int v,int l,int r,int idx)
{
    if(r<idx || l>idx) return;
    if(l==r)
    {
        tree[v]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    update(v*2,l,mid,idx);
    update(v*2+1,mid+1,r,idx);
    tree[v]=tree[v*2]+tree[v*2+1];
}
int query(int v,int l,int r,int s,int e)
{
    if(l>e || r<s) return 0;
    if(l>=s && r<=e) return tree[v];
    int mid=(l+r)/2;
    
    int lnum=query(v*2,l,mid,s,e);
    int rnum=query(v*2+1,mid+1,r,s,e);
    return lnum+rnum;
}