# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
pair<int,int> arr[100010];
int brr[200010];
int tree[600010];
int lazy[600010];
void prop(int node,int s,int e)
{
    tree[node]=max(tree[node],lazy[node]);
    if(s!=e)
    {
        for(int i=node*2;i<=node*2+1;i++)
        {
            lazy[i]=max(lazy[i],lazy[node]);
        }        
    }
    lazy[node]=0;
}
void update(int node,int s,int e,int l,int r,int mx)
{
    prop(node,s,e);
    if(s>r || e<l)
        return;
    if(s>=l && e<=r)
    {
        lazy[node]=mx;
        prop(node,s,e);
        return;
    }
    int mid=(s+e)/2;
    update(node*2,s,mid,l,r,mx);
    update(node*2+1,mid+1,e,l,r,mx);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}
int query(int node,int s,int e,int l,int r)
{
    prop(node,s,e);
    if(s>r || e<l)
        return 0;
    if(s>=l && e<=r)
        return tree[node];
    int mid=(s+e)/2;
    return max(query(node*2,s,mid,l,r),query(node*2+1,mid+1,e,l,r));
}
void print(int node,int s,int e)
{
    cout<<s<<" "<<e<<" | "<<tree[node]<<" "<<lazy[node]<<'\n';
    if(s==e) return;
    int mid=(s+e)/2;
    print(node*2,s,mid);
    print(node*2+1,mid+1,e);
}
int main()
{
    fastio;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
        v.push_back(arr[i].second);
        v.push_back(arr[i].second+arr[i].first-1);
        arr[i]={arr[i].second,arr[i].first+arr[i].second-1};
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<n;i++)
    {
        int idx=lower_bound(v.begin(),v.end(),arr[i].first)-v.begin();
        arr[i].first=idx;
        idx=lower_bound(v.begin(),v.end(),arr[i].second)-v.begin();
        arr[i].second=idx;        
    }
    for(int i=0;i<n;i++)
    {
        int mx=query(1,0,200000,arr[i].first,arr[i].second);
        update(1,0,200000,arr[i].first,arr[i].second,mx+1);
        //print(1,0,20);
    }
        
    cout<<query(1,0,200000,0,200000);
    //print(1,0,20);
}

// 2 5
// 1 3
// 3 5
// 5 8
// 6 9