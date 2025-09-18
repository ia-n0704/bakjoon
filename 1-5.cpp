# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
struct line
{
    ll x,y1,y2;
    ll num;
};
int n;
vector<line> v;
ll cnt[1600010];
ll seg[1600010];
map<ll,ll> m;
ll rev_m[400010];
bool compare(line a,line b)
{
    return a.x<b.x;
}
void update(int v,int st,int en, int l,int r,int a)
{
    if(st>r || en<l) return;
    if(l<=st && r>=en)
    {
        cnt[v]+=a;
        if(cnt[v])
            seg[v]=rev_m[en]-rev_m[st-1];
        else seg[v]=(st==en)?0:seg[v*2]+seg[v*2+1];
        return;
    }
    int mid=(st+en)>>1;
    update(v*2,st,mid,l,r,a);
    update(v*2+1,mid+1,en,l,r,a);   
    if(cnt[v])
        seg[v]=rev_m[en]-rev_m[st-1];
    else seg[v]=(st==en)?0:seg[v*2]+seg[v*2+1];     
}
int main()
{
    fastio;
    cin>>n;
    vector<ll> v2;
    for(int i=0;i<n;i++)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        v.push_back({a,c,d,1});
        v.push_back({b,c,d,-1});
        v2.push_back(c);
        v2.push_back(d);
    }
    sort(all(v2));
    v2.erase(unique(all(v2)),v2.end());
    sort(all(v),compare);
    for(int i=0;i<v2.size();i++)
    {
        m[v2[i]]=i;
        rev_m[i]=v2[i];
    }
    for(int i=0;i<v.size();i++)
    {
        v[i].y1=m[v[i].y1];
        v[i].y2=m[v[i].y2];
        //cout<<v[i].y1<<" "<<v[i].y2<<'\n';
    }
    ll res=0;
    for(int i=0;i<v.size();i++)
    {
        if(i!=0)
        {
            //cout<<seg[1]<<" ";
            res+=(v[i].x-v[i-1].x)*seg[1];
        }
        update(1,1,v2.size()-1,v[i].y1+1,v[i].y2,v[i].num);
    }
    cout<<res;
}