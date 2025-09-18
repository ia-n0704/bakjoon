#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[200010];
int cnt[200010];
vector<int> v[200010];
int brr[200010];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        cnt[b]++;
    }
    queue<pair<int,int>> q;
    for(int i=1;i<=n;i++)
        if(cnt[i]==0) q.push({i,1});
    int mx=0;
    while(!q.empty())
    {
        int a=q.front().first;
        int b=q.front().second;
        q.pop();
        mx=max(mx,b);
        brr[b]|=(arr[a]+1);
        for(auto i:v[a])
        {
            cnt[i]--;
            if(cnt[i]==0)
                q.push({i,b+1});
        }
    }
    int ans=1e9;
    for(int j=1;j<=2;j++)
    {
        if((brr[1]&j)==0) continue;
        int temp=j;
        int res=0;
        if(brr[1]==3) res++;
        for(int i=2;i<=mx;i++)
        {
            if(brr[i]==3)
            {
                res++;
                temp^=3;
            }
            else if(temp!=brr[i])
            {
                res++;
                temp=brr[i];
            }
        }        
        ans=min(ans,res);
    }
    cout<<ans;
}