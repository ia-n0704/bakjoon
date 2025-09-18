# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,q;
struct P
{
    int x,y,st,en;
};
struct L
{
    int x,y,z;
};
stack<L> s;
vector<P> v;
map<pair<int,int>,int> m;
P T[200010];
vector<pair<int,int>> seg[200010];
pair<int,int> Q[200010];
int parent[200010];
int R[200010];
int par(int a)
{
    if(a==parent[a]) return a;
    else return par(parent[a]);
}
int _union(int a,int b)
{
    if(a==b)
        return 0;
    if(R[a]<R[b]) swap(a,b);
    parent[b]=a;
    if(R[a]==R[b])
    {
        R[a]++;
        s.push({a,b,1});
    }
    else s.push({a,b,0});
    return 1;
}
void back(int cnt)
{
    for(int i=1;i<=cnt;i++)
    {
        if(s.empty()) break;
        auto a=s.top();
        s.pop();
        parent[a.y]=a.y;
        if(a.z==1) R[a.x]--;
    }
}
void update(int node,int l,int r,int st,int en,pair<int,int> a)
{
    if(st<=l && r<=en)
    {
        seg[node].push_back(a);
        return;
    }
    if(l>en || r<st)
        return;
    int mid=(l+r)/2;
    update(node*2,l,mid,st,en,a);
    update(node*2+1,mid+1,r,st,en,a);
}
void dnc(int node,int l,int r)
{
    int cnt=0;
    for(auto i:seg[node])
        cnt+=_union(par(i.first),par(i.second));
    if(l==r)
    {
        int num=0;
        if(par(Q[l].first)==par(Q[l].second)) num=1;
        cout<<num<<'\n';
        back(cnt);
        return;
    }
    int mid=(l+r)/2;
    dnc(node*2,l,mid);
    dnc(node*2+1,mid+1,r);
    back(cnt);
}
int main()
{
    fastio;
    cin>>n>>q;
    int idx=1;
    int cnt=0;
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=1;i<=q;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(b>c) swap(b,c);
        if(a==1)
        {
            m[{b,c}]=idx;
            T[idx]={b,c,cnt+1,-1};
        }
        else if(a==2)
        {
            int temp=m[{b,c}];
            T[temp].en=cnt;
            v.push_back(T[temp]);
        }
        else
        {
            cnt++;
            Q[cnt]={b,c};
        }
        idx++;
    }
    for(int i=1;i<=q;i++)
    {
        if(T[i].en==-1)
        {
            T[i].en=cnt;
            v.push_back(T[i]);
        }
    }
    for(auto i:v)
    {
        //cout<<i.x<<" "<<i.y<<" | "<<i.st<<" "<<i.en<<'\n';
        update(1,1,cnt,i.st,i.en,{i.x,i.y});
    }
    dnc(1,1,cnt);
}