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
vector<pair<int,pair<int,int>>> v;
pair<int,int> query[100010];
int L[100010],R[100010];
pair<int,int> ans[100010];
vector<int> M[100010];

//여기서부터 유파 (find, union)
int cnt[100010];
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
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({c,{a,b}});
    }
    cin>>q;
    for(int i=1;i<=q;i++)
        cin>>query[i].first>>query[i].second;
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
                    ans[j]={a.first,-cnt[_find(query[j].first)]};
                    R[j]=i+1;
                }
                else L[j]=i+1;
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        if(L[i]==m) cout<<-1<<'\n';
        else cout<<ans[i].first<<" "<<ans[i].second<<'\n';
    }
}