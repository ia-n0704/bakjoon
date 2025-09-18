# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
struct T
{
    int flag;
    int l,r;
};
int n,q;
string s;
int arr[500010];
T tree[1000010];
void init(int v,int st,int en)
{
    if(st==en)
    {
        tree[v]={1,s[st-1],s[en-1]};
        return;
    }
    int mid=(st+en)/2;
    init(v*2,st,mid);
    init(v*2+1,mid+1,en);
    if(tree[v*2].flag && tree[v*2+1].flag)
    {
        if(tree[v*2].r!=tree[v*2+1].l)
            tree[v].flag=1;
    }
    tree[v].l=tree[v*2].l;
    tree[v].r=tree[v*2+1].r;
}
void update(int v,int st,int en,int a,int b)
{
    if(st==en) return;
    if(a>en || b<st)
        return;
    if(a<=st && b>=en)
    {
        tree[v].l^=1;
        tree[v].r^=1;
    }
    
    int mid=(st+en)/2;
    update(v*2,st,mid,a,b);
    update(v*2+1,mid+1,en,a,b);
    if(tree[v*2].flag && tree[v*2+1].flag)
    {
        if(tree[v*2].r!=tree[v*2+1].l)
            tree[v].flag=1;
    }
}
T query(int v,int st,int en,int a,int b)
{
    if(a>en || b<st)
        return {1,-1,-1};
    if(a<=st && b>=en)
        return tree[v];
    int mid=(st+en)/2;
    T first=query(v*2,st,mid,a,b);
    T second=query(v*2+1,mid+1,en,a,b);
    T result;
    if(first.flag && second.flag)
    {
        if(first.r!=second.l || first.r==-1 || second.l==-1)
            result.flag=1;
    }
    result.l=first.l;
    result.r=second.r;
    return result;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string t;
    cin>>n>>q;
    cin>>s;
    init(1,1,n);
    while(q--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            update(1,1,n,b,c);
        }
        else
        {
            T res=query(1,1,n,b,c);
            if(res.flag)
                cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}