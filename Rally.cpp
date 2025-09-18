# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m;
pair<int,int> arr[1000010];
vector<int> v[500010];
int cnt[500010];
int order[500010];
int idx[500010];
int front[500010],back[500010];
int seg[2000010];
int dep;

//펜윅 트리 (구간 업데이트 지원)
void update(int l,int r,int num)
{
    l+=dep,r+=dep;
    while(l<r)
    {
        if(l%2)
        {
            seg[l]=max(seg[l],num);
            l++;
        }
        if(!(r%2))
        {
            seg[r]=max(seg[r],num);
            r--;
        }
        l/=2,r/=2;
    }//국영수해 노재원
    if(l==r) seg[l]=max(seg[l],num);
}
int query(int x)
{
    x+=dep;
    int ans=0;
    while(x>0)
    {
        ans=max(ans,seg[x]);
        x/=2;
    }
    return ans;
}

int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>arr[i].first>>arr[i].second;
        cnt[arr[i].second]++;
        v[arr[i].first].push_back(arr[i].second);
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(cnt[i]==0) q.push(i);
    int num=0;
    while(!q.empty())
    {
        auto a=q.front();
        q.pop();
        order[a]=++num;
        idx[order[a]]=a;
        for(auto i:v[a])
        {
            cnt[i]--;
            if(cnt[i]==0)
                q.push(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        int x=idx[i];
        for(auto j:v[x])
            front[order[j]]=max(front[order[j]],front[i]+1);
    }
    for(int i=n;i>=1;i--)
    {
        int x=idx[i];
        for(auto j:v[x])
            back[i]=max(back[i],back[order[j]]+1);
    }
    dep=1;
    while(dep<=n) dep*=2;
    for(int i=1;i<=m;i++)
    {
        int s=order[arr[i].first],e=order[arr[i].second];
        update(s+1,e-1,front[s]+back[e]+1);
        //cout<<s<<" "<<e<<" "<<front[s]+back[e]+1<<'\n';
    }
    // for(int i=1;i<=n;i++)
    //     cout<<order[i]<<" "<<query(order[i])<<'\n';
    
    for(int i=1;i<=n;i++)
        front[i]=max(front[i],front[i-1]);
    for(int i=n;i>=1;i--)
        back[i]=max(back[i],back[i+1]);
    vector<pair<int,int>> ans;
    for(int i=1;i<=n;i++)
    {
        int temp=max(front[order[i]-1],back[order[i]+1]);
        temp=max(temp,query(order[i]));
        //cout<<query(order[i])<<'\n';
        ans.push_back({temp,i});
    }
    sort(ans.begin(),ans.end());
    cout<<ans[0].second<<" "<<ans[0].first;
}