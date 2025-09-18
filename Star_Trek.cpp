/*#include <bits/stdc++.h>
#define N 100010
#define inf 1e16
using namespace std;
typedef long long ll;
struct line
{
    ll a,b;
    double x;
    ll f(ll x)
    {
        return a*x+b;
    }
};
vector <line> L;
int n;
ll D[N],sum[N],P[N],R[N];
ll dp[N];
double cross(line x,line y)
{
    return (double)(y.b-x.b)/(x.a-y.a);
}
void _insert(ll a,ll b)
{
    if(L.size()==0)
    {
        L.push_back({a,b,-inf});
        return;
    }
    line k={a,b};
    while(L.size())
    {
        line top=L.back();
        if(top.x>cross(L.back(),k))
            L.pop_back();
        else break;
    }
    
    k.x=cross(L.back(),k);
    L.push_back(k);    
    cout<<" | "<<L.size()<<" "<<k.x<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        cin>>D[i];
        sum[i]=sum[i-1]+D[i];
    }
    for(int i=1;i<n;i++)
        cin>>P[i]>>R[i];
    _insert(-R[1],-P[1]);
    for(int i=2;i<=n;i++)
    {
        int l=0,r=L.size()-1;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(L[mid+1].x>=sum[i])
                r=mid;
            else l=mid+1;
        }
        dp[i]=-(L[r].f(sum[i]));
        cout<<r<<" "<<L[r].a<<" "<<L[r].b<<" "<<L[r].x<<" "<<dp[i]<<'\n';
        if(i==n) continue;
        _insert(-R[i],-(dp[i]+P[i]-R[i]*sum[i]));
    }
    cout<<dp[n];
}*/

/*
기울기 값의 단조성 확인 불가.
-> cht 사용불가능. 
 : 리차오 트리 이용.
*/

//#S2 리차오 트리
#include <bits/stdc++.h>
#define N 100010
using namespace std;
typedef long long ll;
const ll inf=1e16;
int n;
ll d[N],sum[N];
ll P[N],R[N];
struct Line
{
    ll a,b;
    ll f(ll x)
    {
        return a*x+b;
    }
};
struct Node
{
    ll l,r;
    ll s,e;
    Line line;
};
struct li_chao
{
    int idx=0;
    vector<Node> tree;
    void _init(ll s,ll e)
    {
        tree.push_back({-1,-1,s,e,{0,inf}});
        idx++;
    }
    void insert(Line k,int node)
    {
        ll s=tree[node].s,e=tree[node].e;
        Line low=tree[node].line,high=k;
        if(low.f(s)>high.f(s))
            swap(low,high);
        if(low.f(e)<=high.f(e))
        {
            tree[node].line=low;
            return;
        }
        ll mid=(s+e)/2;
        if(low.f(mid)<=high.f(mid))
        {
            tree[node].line=low;
            if(tree[node].r==-1)
            {
                tree.push_back({-1,-1,mid+1,e,{0,inf}});
                tree[node].r=idx++;
            }
            insert(high,tree[node].r);
        }
        else
        {
            tree[node].line=high;
            if(tree[node].l==-1)
            {
                tree.push_back({-1,-1,s,mid,{0,inf}});
                tree[node].l=idx++;
            }
            insert(low,tree[node].l);
        }
    }
    ll query(ll x,int node)
    {
        if(node==-1) return inf;
        ll s=tree[node].s,e=tree[node].e;
        ll mid=(s+e)/2;
        if(x<=mid) return min(tree[node].line.f(x),query(x,tree[node].l));
        else return min(tree[node].line.f(x),query(x,tree[node].r));
    }
}L;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        cin>>d[i];
        sum[i]=sum[i-1]+d[i];
    }
    for(int i=1;i<=n;i++)
        cin>>P[i]>>R[i];
    L._init(0,1e10);
    L.insert({R[1],P[1]},0);
    for(int i=2;i<=n;i++)
    {
        ll num=L.query(sum[i],0);
        if(i==n)
        {
            cout<<num;
            continue;
        }
        L.insert({R[i],num+P[i]-R[i]*sum[i]},0);
    }
}