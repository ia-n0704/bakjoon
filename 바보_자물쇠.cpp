# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
string s;
int arr[100010];
int q;
struct seg{
    struct Node
    {
        int zsum,osum,num;
    };
    Node seg[400010];
    Node merge(Node a,Node b)
    {
        return {a.zsum+b.zsum,a.osum+b.osum,min(a.num+b.zsum,a.osum+b.num)};
    }
    void init(int node,int l,int r,vector <int> &a)
    {
        if(l==r)
        {
            if(a[l]==0)
                seg[node]={1,0,0};
            else
                seg[node]={0,1,0};
            return;
        }
        int mid=(l+r)/2;
        init(node*2,l,mid,a);
        init(node*2+1,mid+1,r,a);
        seg[node]=merge(seg[node*2],seg[node*2+1]);
        //cout<<l<<" "<<r<<" | "<<seg[node].zsum<<" "<<seg[node].osum<<" "<<seg[node].num<<'\n';
    }
    void update(int node,int l,int r,int idx,int x)
    {
        if(l>idx || r<idx) return;
        if(l==r)
        {
            if(x)
                seg[node]={0,1,0};
            else
                seg[node]={1,0,0};
            return;
        }
        int mid=(l+r)/2;
        update(node*2,l,mid,idx,x);
        update(node*2+1,mid+1,r,idx,x);
        seg[node]=merge(seg[node*2],seg[node*2+1]);
        //cout<<l<<" "<<r<<" | "<<seg[node].zsum<<" "<<seg[node].osum<<" "<<seg[node].num<<'\n';
    }
}tree[30];
int init()
{
    int res=0;
    for(int i=0;i<25;i++)
    {
        vector<int> a;
        for(int j=0;j<s.length();j++)
        {
            a.push_back(arr[j]>i);
        }
        tree[i].init(1,0,s.length()-1,a);
        res+=tree[i].seg[1].num;
    }
    return res;
}
int update(int x,int a)
{
    int res=0;
    for(int i=0;i<25;i++)
    {
        tree[i].update(1,0,s.length()-1,x,a>i);
        res+=tree[i].seg[1].num;
    }
    return res;
}
int main()
{
    fastio;
    cin>>s;
    for(int i=0;i<s.length();i++)
        arr[i]=s[i]-'a';
    cout<<init()<<'\n';
    cin>>q;
    while(q--)
    {
        int a;
        string t;
        cin>>a>>t;
        int b=t[0]-'a';
        cout<<update(a-1,b)<<'\n';
    }
}