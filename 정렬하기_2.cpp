#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[200010];
int idx[200010];
int num_idx[200010];
int cur[200010];
int temparr[200010];
pair<int,int> query[201010];
int res;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    cin>>m;
    for(int i=1;i<=m;i++) cin>>query[i].first>>query[i].second;
    for(int i=1;i<=n;i++) temparr[i]=arr[i];
    sort(temparr+1,temparr+n+1);
    int flag=0;
    for(int i=1;i<=n;i++) if(temparr[i]!=arr[i]) flag=1;
    if(!flag)
    {
        cout<<0;
        return 0;
    }
    int l=0,r=n;
    while(l<r)
    {
        int mid=(l+r)/2;
        int mex=0;
        for(int i=1;i<=n;i++)
        {
            temparr[i]=arr[i];
            idx[arr[i]]=i;
        }
        
        for(int i=1;i<=mid;i++)
        {
            int a=query[i].first+1,b=query[i].second+1;
            int tempa=idx[temparr[a]],tempb=idx[temparr[b]];
            swap(idx[temparr[a]],idx[temparr[b]]);
            swap(temparr[tempa],temparr[tempb]);
        }
        
        for(int i=1;i<=n;i++)
        {
            temparr[i]=arr[i];
            cur[arr[i]]=i;
            num_idx[idx[temparr[i]]]=i;
        }
        for(int i=1;i<=mid;i++)
        {
            int a=query[i].first+1,b=query[i].second+1;
            swap(temparr[a],temparr[b]);
            swap(num_idx[idx[temparr[a]]],num_idx[idx[temparr[b]]]);
            swap(cur[temparr[a]],cur[temparr[b]]);     
            while(idx[mex]==mex+1) mex++;
            int temp=temparr[num_idx[mex+1]];
            swap(idx[mex],idx[temparr[num_idx[mex+1]]]);
            swap(temparr[cur[mex]],temparr[num_idx[mex+1]]);
            swap(cur[mex],cur[temp]);
            while(idx[mex]==mex+1) mex++;
        }
        if(mex>=n) r=mid;
        else l=mid+1;
    }
    r=l;
    cout<<r<<'\n';
    int mex=0;
    for(int i=1;i<=n;i++)
    {
        idx[arr[i]]=i;
        temparr[i]=arr[i];
    }
    for(int i=1;i<=r;i++)
    {
        int a=query[i].first+1,b=query[i].second+1;
        int tempa=idx[temparr[a]],tempb=idx[temparr[b]];
        swap(idx[temparr[a]],idx[temparr[b]]);
        swap(temparr[tempa],temparr[tempb]);
    }
    for(int i=1;i<=n;i++)
    {
        temparr[i]=arr[i];
        cur[arr[i]]=i;
        num_idx[idx[temparr[i]]]=i;
    }
    
    for(int i=1;i<=r;i++)
    {
        int a=query[i].first+1,b=query[i].second+1;
        swap(temparr[a],temparr[b]);
        swap(num_idx[idx[temparr[a]]],num_idx[idx[temparr[b]]]);
        swap(cur[temparr[a]],cur[temparr[b]]);     
        while(idx[mex]==mex+1) mex++;
        if(mex>=n) cout<<"0 0\n";
        else cout<<num_idx[mex+1]-1<<" "<<cur[mex]-1<<'\n';
        int temp=temparr[num_idx[mex+1]];
        swap(idx[mex],idx[temparr[num_idx[mex+1]]]);
        //cout<<"| "<<mex<<" "<<num_idx[mex+1]-1<<'\n';
        swap(temparr[cur[mex]],temparr[num_idx[mex+1]]);
        swap(cur[mex],cur[temp]);
        while(idx[mex]==mex+1) mex++;
    }
}