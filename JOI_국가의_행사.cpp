# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m,k,q;
vector<pair<int,int>> v[100010];
vector<pair<int,pair<int,int>>> v2;
int dist[100010];
map<int,int> m2;
vector<int> num[100010];
int L[100010],R[100010];
vector<int> mid[100010];
int cnt[100010];
int ans[100010];
pair<int,int> query[100010];
int _find(int x)
{
    if(cnt[x]<0) return x;
    else return cnt[x]=_find(cnt[x]);
}
void _union(int x,int y)
{
    x=_find(x);
    y=_find(y);
    if(x==y) return;
    if(cnt[x]<cnt[y])
        swap(x,y);
    cnt[x]+=cnt[y];
    cnt[y]=x;
}
int main()
{
    fastio;
    cin>>n>>m>>k>>q;

    for(int i=1;i<=m;i++)   //그래프 구성
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
        v2.push_back({-1,{a,b}});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=1;i<=k;i++)   //시작점 - 축제 도시
    {
        int a;
        cin>>a;
        pq.push({0,a});
    }
    fill(dist+1,dist+n+1,1e9);
    while(!pq.empty())  //축제 도시를 시작으로 다익.
    {
        auto a=pq.top();
        pq.pop();
        int co=a.first;
        int cur=a.second;
        if(dist[cur]<=co) continue;
        dist[cur]=co;
        for(auto i:v[cur])
        {
            if(dist[i.first]<co+i.second) continue;
            pq.push({co+i.second,i.first});
        }
    }
    for(int i=0;i<m;i++)
        v2[i].first=min(dist[v2[i].second.first],dist[v2[i].second.second]);
    vector<int> arr;    //거리를 기준으로 좌표압축.
    for(int i=1;i<=m;i++)
        arr.push_back(v2[i].first);
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    reverse(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++)
        m2[arr[i]]=i;
    int sz=arr.size()-1;
    for(int i=0;i<m;i++)
        num[m2[v2[i].first]].push_back(i);
    // for(int i=0;i<=sz;i++)
    // {
    //     cout<<"i : "<<i<<", num : "<<arr[i]<<'\n';
    //     for(auto j:num[i])
    //         cout<<j<<" ";
    //     cout<<'\n';
    // }
    
    for(int i=1;i<=q;i++)   //쿼리 입력
        cin>>query[i].first>>query[i].second;
    
    fill(R+1,R+q+1,sz);
    while(1)
    {
        for(int i=0;i<=sz;i++)
            mid[i].clear();
        int flag=0;
        for(int i=1;i<=q;i++)
        {
            if(L[i]<R[i])
            {
                flag=1;
                mid[(L[i]+R[i])/2].push_back(i);
            }
        }
        if(!flag) break;

        fill(cnt+1,cnt+n+1,-1);
        for(int i=0;i<=sz;i++)
        {
            for(auto j:num[i])
                _union(v2[j].second.first,v2[j].second.second);
            for(auto j:mid[i])
            {
                if(_find(query[j].first)==_find(query[j].second))
                {
                    //cout<<i<<" "<<j<<'\n';
                    ans[j]=arr[i];
                    R[j]=i;
                }
                else L[j]=i+1;
            }
        }
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
}