#include <bits/stdc++.h>
using namespace std;
int n,s;
int arr[100010],sum[100010];
int res[100010];
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+arr[i];

    for(int i=1;i<=n;i++)
    {
        int l=0,r=min(i,n-i);
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(sum[i]-sum[i-mid]>s)
                r=mid-1;
            else if(sum[i+mid]-sum[i]>s)
                r=mid-1;
            else l=mid+1;
        }
        //printf("%d %d\n",i,r);
        res[i-r+1]=max(res[i-r+1],r);
    }
    for(int i=1;i<=n;i++)
    {
        res[i]=max(res[i],res[i-1]-1);
    }
    for(int i=1;i<=n;i++)
        cout<<res[i]*2<<'\n';
}