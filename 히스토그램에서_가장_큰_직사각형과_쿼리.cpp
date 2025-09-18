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
int arr[100010];
int ans[100010];
vector<int> brr;
vector<int> num[100010];
vector<int> mid[100010];
int L[100010],R[100010];
pair<int,pair<int,int>> query[100010];
map<int,int> m;
struct Seg
{
    int left,right,ans,num;
}seg[400040];
void _init(int v,int l,int r)
{
    seg[v]={0,0,0,1};
    if(l==r) return;
    int mid=(l+r)/2;
    _init(v*2,l,mid);
    _init(v*2+1,mid+1,r);
}
Seg _merge(Seg x,Seg y)
{
    Seg temp;
    if(x.ans==x.num) temp.left=x.ans+y.left;
    else temp.left=x.left;
    if(y.ans==y.num) temp.right=x.right+y.ans;
    else temp.right=y.right;
    temp.ans=max(x.right+y.left,max(x.ans,y.ans));
    temp.num=x.num+y.num;
    return temp;
}
void _update(int v,int l,int r,int idx)
{
    if(l>idx || r<idx) return;
    if(l==r)
    {
        seg[v]={1,1,1,1};
        return;
    }
    int mid=(l+r)/2;
    _update(v*2,l,mid,idx);
    _update(v*2+1,mid+1,r,idx);
    seg[v]=_merge(seg[v*2],seg[v*2+1]);
}
Seg _query(int v,int l,int r,int s,int e)
{
    if(l>e || r<s) return {0,0,0,1};
    else if(l>=s && r<=e) return seg[v];
    int mid=(l+r)/2;
    return _merge(_query(v*2,l,mid,s,e),_query(v*2+1,mid+1,r,s,e));
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        brr.push_back(arr[i]);
    }
    sort(brr.begin(),brr.end());
    brr.erase(unique(brr.begin(),brr.end()),brr.end());
    int sz=brr.size()-1;
    for(int i=0;i<=sz;i++)
        m[brr[i]]=i;
    for(int i=1;i<=n;i++)
        num[m[arr[i]]].push_back(i);
    reverse(brr.begin(),brr.end());
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        query[i]={c,{a,b}};
    }
    fill(R+1,R+q+1,sz);
    while(1)
    {
        for(int i=0;i<=sz;i++) mid[i].clear();
        int flag=0;
        for(int i=1;i<=q;i++)
        {
            if(L[i]<R[i])
            {
                mid[(L[i]+R[i])/2].push_back(i);
                flag=1;
            }
        }
        if(!flag) break;
        _init(1,1,n);
        for(int i=0;i<=sz;i++)
        {
            for(auto j:num[sz-i])
            {
                //if(j==2) cout<<"i : "<<i<<'\n';
                _update(1,1,n,j);
            }
            for(auto j:mid[i])
            {
                //cout<<i<<" "<<j<<" | "<<_query(1,1,n,query[j].second.first,query[j].second.second).ans<<'\n';
                if(_query(1,1,n,query[j].second.first,query[j].second.second).ans>=query[j].first)
                {
                    ans[j]=brr[i];
                    R[j]=i;
                }
                else L[j]=i+1;
            }
            //Seg T=_query(1,1,n,1,n);
            //cout<<i<<"일 때 전체 쿼리 : "<<T.left<<" "<<T.right<<" "<<T.ans<<" "<<T.num<<'\n';
            //cout<<_merge({2,1,2,4},{2,1,2,4}).right<<'\n';
        }
    }
    for(int i=1;i<=q;i++)
    {
        if(ans[i]==0) cout<<brr[sz]<<'\n';
        else cout<<ans[i]<<'\n';
    }
}