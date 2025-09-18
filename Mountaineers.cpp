# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m,q;
int arr[510][510];
vector<pair<int,pair<int,int>>> v;
pair<int,int> query[1000010];
int L[1000010],R[1000010];
int ans[100010];
vector<int> M[1000010];
int X[5]={0,1};
int Y[5]={1,0};

int get_idx(int x,int y)
{
    return x*m+y;
}

//여기서부터 유파 (find, union)
int cnt[1000010];
int _find(int x)
{
    if(cnt[x]<0) return x;
    return cnt[x]=_find(cnt[x]);
}
void _union(int x,int y)
{
    x=_find(x);
    y=_find(y);
    if(x==y) return;
    if(cnt[x]>cnt[y])
        swap(x,y);
    cnt[x]+=cnt[y];
    cnt[y]=x;
}
//union-find end

int main()
{
    fastio;
    cin>>n>>m>>q;
    int temp=m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<2;k++)
            {
                int nx=i+X[k],ny=j+Y[k];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                int f_node=get_idx(i,j);
                int s_node=get_idx(nx,ny);
                v.push_back({max(arr[i][j],arr[nx][ny]),{f_node,s_node}});
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--,b--,c--,d--;
        int f=get_idx(a,b);
        int s=get_idx(c,d);
        if(f<s) swap(f,s);
        query[i]={f,s};
    }
    n=n*m;
    m=v.size();
    sort(v.begin(),v.end());  
    fill(R,R+q+1,m+1);
    while(1)
    {
        for(int i=0;i<=m+1;i++)
            M[i].clear();
        int flag=0;
        for(int i=1;i<=q;i++)
        {
            if(L[i]+1<R[i])
            {
                M[(L[i]+R[i])/2].push_back(i);
                flag=1;
            }
        }
        if(!flag) break;
        fill(cnt,cnt+n+1,-1);
        for(int i=0;i<v.size();i++)
        {
            auto a=v[i];
            _union(a.second.first,a.second.second);
            //cout<<"| "<<a.second.first<<" "<<a.second.second<<'\n';
            for(auto j:M[i+1])
            {
                //cout<<query[j].first<<" "<<query[j].second<<'\n';
                //cout<<_find(query[j].first)<<" "<<_find(query[j].second)<<'\n'<<'\n';
                if(_find(query[j].first)==_find(query[j].second))
                {
                    //cout<<i<<" "<<j<<'\n';
                    ans[j]=a.first;
                    R[j]=i+1;
                }
                else L[j]=i+1;
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        if(query[i].first==query[i].second) cout<<arr[query[i].first/temp][query[i].first%temp]<<'\n';
        else cout<<ans[i]<<'\n';
    }
}