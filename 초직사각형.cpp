#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,k;
priority_queue<ll> pq[5];
ll num[5];
vector<pair<ll,ll>> ans;
int main()
{
    fastio;
    cin>>n>>k;
    for(int i=0;i<4;i++) cin>>num[i];
    for(int i=1;i<=n;i++)
    {
        char x;
        ll y;
        cin>>x>>y;
        pq[x-'A'].push(y);
    }
    for(int i=1;i<=k;i++)
    {
        int mx;
        int idx=0;
        for(int j=1;j<4;j++)
        {
            if(pq[j].empty()) continue;
            if(pq[idx].empty() || (num[idx]+pq[idx].top())*num[j]<(num[j]+pq[j].top())*num[idx])
                idx=j;            
        }
        num[idx]+=pq[idx].top();
        ans.push_back({idx,pq[idx].top()});
        pq[idx].pop();
    }
    for(auto i:ans) cout<<char(i.first+'A')<<" "<<i.second<<'\n';
}