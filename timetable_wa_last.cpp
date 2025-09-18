#include <bits/stdc++.h>
using namespace std;
int arr[1000010];
int ch[1000010];
int n,m,a,b;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>a>>b;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    int l;
    for(int i=1;i<=a;i++)
    {
        cin>>l;
        ch[l]=1;
    }
    for(int i=1;i<=b;i++)
    {
        cin>>l;
        ch[l]=-1;
    }
    int last=0,ans=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(ch[arr[i]]!=last)
        {
            if(cnt>=3) ans+=cnt*last;
            cnt=0; 
        }
        if(ch[arr[i]]) cnt++;
        last=ch[arr[i]];
    }
    cout<<ans;
}