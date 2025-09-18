#include<bits/stdc++.h>
using namespace std;
int n,m;
pair<int,pair<int,int>> arr[2010];
int ch[2010];
int res[2010];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>arr[i].second.first>>arr[i].second.second;
        arr[i].first=arr[i].second.second-arr[i].second.first;
    }
    sort(arr+1,arr+m+1);
    int mn=arr[1].first+1;
    int num=0;
    for(int i=arr[1].second.first;i<=arr[1].second.second;i++)
    {
        num++;
        res[i]=num;
    }
    for(int i=2;i<=m;i++)
    {
        int l=arr[i].second.first;
        int r=arr[i].second.second;
        fill(ch,ch+1001,0);
        for(int j=l;j<=r;j++)
            ch[res[j]]=1;
        int num=1;
        int cnt=0;
        for(int j=l;j<=r;j++)
        {
            cnt++;
            if(res[j]) continue;
            if(cnt>mn)
            {
                res[j]=cnt%mn;
                continue;
            }
            while(ch[num]) num++;
            res[j]=num;
            ch[num]=1;
        }
    }
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
}