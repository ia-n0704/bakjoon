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
const ll mod=998'244'353;
const ll MOD=1e9+7;
int n,m,k,q;
vector<pii> ri,le;
pii sp[200010][22];
pii seg[800010][22];
void update(int v,int l,int r,int seg_num,int idx,pii num)
{
    if(l>idx || r<idx) return;
    if(l==r)
    {
        seg[v][seg_num]=num;
        return;
    }
    int mid=(l+r)/2;
    update(v*2,l,mid,seg_num,idx,num);
    update(v*2+1,mid+1,r,seg_num,idx,num);
    seg[v][seg_num]={min(seg[v*2][seg_num].fi,seg[v*2+1][seg_num].fi),max(seg[v*2][seg_num].se,seg[v*2+1][seg_num].se)};
}
pii query(int v,int l,int r,int s,int e,int seg_num)
{
    if(l>e || r<s) return {1e9,-1e9};
    else if(l>=s && r<=e) return seg[v][seg_num];
    int mid=(l+r)/2;
    pii a=query(v*2,l,mid,s,e,seg_num),b=query(v*2+1,mid+1,r,s,e,seg_num);
    return {min(a.fi,b.fi),max(a.se,b.se)};
}
int main()
{
    fastio;
    cin>>n>>k>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a<b)
            le.push_back({a,b});
        else ri.push_back({a,b});
    }
    sort(all(le));
    sort(all(ri));
    reverse(all(ri));
    priority_queue<pii> pq;
    int idx=0;
    for(int i=1;i<=n;i++)
    {
        while(idx<le.size() && le[idx].fi<=i)
        {
            pq.push({le[idx].se,le[idx].fi});
            idx++;
        }
        while(!pq.empty())
        {
            auto a=pq.top();
            if(min(a.se+k-1,a.fi-1)>=i) break;
            else pq.pop();
        }
        if(pq.empty())
            sp[i][0].se=i;
        else sp[i][0].se=pq.top().fi;
    }

    priority_queue<pii,vector<pii>,greater<pii>> pq2;
    idx=0;
    for(int i=n;i>=1;i--)
    {
        while(idx<ri.size() && ri[idx].fi>=i)
        {
            pq2.push({ri[idx].se,ri[idx].fi});
            idx++;
        }
        while(!pq2.empty())
        {
            auto a=pq2.top();
            if(max(a.se-k+1,a.fi+1)<=i) break;
            else pq2.pop();
        }
        if(pq2.empty())
            sp[i][0].fi=i;
        else sp[i][0].fi=pq2.top().fi;
    }

    for(int i=0;i<=20;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>0) sp[j][i]=query(1,1,n,sp[j][i-1].fi,sp[j][i-1].se,i-1);
            update(1,1,n,i,j,sp[j][i]);
        }
    }
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        int res=0;
        pii cur={a,a};
        for(int i=20;i>=0;i--)
        {
            //cout<<cur.fi<<" "<<cur.se<<'\n';
            pii x=query(1,1,n,cur.fi,cur.se,i);
            if(x.fi>b || x.se<b)
            {
                cur=x;
                res+=(1<<i);
            }
        }
        if(cur.fi>b || cur.se<b)
        {
            res++;
            cur=query(1,1,n,cur.fi,cur.se,0);
        }
        if(cur.fi>b || cur.se<b)
            cout<<"-1\n";
        else cout<<res<<'\n';
    }
}
