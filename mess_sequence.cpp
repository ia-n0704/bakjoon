#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll arr[1000010],brr[1000010];
ll res[1000010];
int group_idx[1000010];
int ch[1000010];
vector<vector<int>> group;
ll group_num[1000010];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) cin>>brr[i];
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(ch[i]) continue;
        int idx=i;
        vector<int> v;
        while(ch[idx]==0)
        {
            group_idx[idx]=v.size();
            v.push_back(idx);
            group_num[idx]=cnt;
            ch[idx]=1;
            idx=brr[idx];
        }
        group.push_back(v);
        cnt++;
    }
    for(int i=1;i<=n;i++)
    {
        ll num=m%(ll)group[group_num[i]].size();
        ll idx=(group_idx[i]+num)%(ll)group[group_num[i]].size();
        res[group[group_num[i]][idx]]=arr[i];
    }
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
}