#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int n,m,k,Q;
struct train
{
    int dest;
    int st,en;
    int idx;
};
int ch[300010];
vector<train> v[100010];
vector<pair<int,int>> ans[100010];
vector<int> ans2[100010],ans3[100010];
int main()
{
    fastio;
    cin>>n>>m>>k>>Q;
    for(int i=1;i<=m;i++)
    {
        int s,ts,d,td;
        cin>>s>>ts>>d>>td;
        v[d].push_back({s,ts,td,i});
    }
    fill(ch,ch+m+1,(int)2e9);
    queue<pair<int,pair<int,int>>> q;
    for(auto i:v[k])
    {
        q.push({i.dest,{i.st,i.en}});
        ch[i.idx]=i.en;
    }

    while(!q.empty())
    {
        auto a=q.front();
        q.pop();
        int cur=a.first;
        int time=a.second.first;
        int mn=a.second.second;
        ans[cur].push_back({time,mn});
        for(auto i:v[cur])
        {
            if(i.dest==k) continue;
            if(ch[i.idx]<=mn) continue;
            if(i.en<=time)
            {
                q.push({i.dest,{i.st,mn}});
                ch[i.idx]=mn;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        sort(ans[i].begin(),ans[i].end());
        stack<pair<int,int>> st;
        for(auto i:ans[i])
        {
            while(!st.empty() && st.top().second>i.second) st.pop();
            st.push(i);
        }
        while(!st.empty())
        {
            ans2[i].push_back(st.top().first);
            ans3[i].push_back(st.top().second);
            st.pop();
        }
        reverse(ans2[i].begin(),ans2[i].end());
        reverse(ans3[i].begin(),ans3[i].end());
    }

    while(Q--)
    {
        int a,b;
        cin>>a>>b;
        int idx=lower_bound(ans2[a].begin(),ans2[a].end(),b)-ans2[a].begin();
        if(idx==ans2[a].size()) cout<<-1<<'\n';
        else
            cout<<ans3[a][idx]<<'\n';
    }
}