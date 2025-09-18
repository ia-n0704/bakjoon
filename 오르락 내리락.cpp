#include <bits/stdc++.h>
using namespace std;
int n;
int arr[200010];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int idx=1;
    int mx=0;
    if(n<=2)
    {
        cout<<n;
        return 0;
    }
    while(idx<=n)
    {
        int flag;
        int temp=idx+2;
        if(idx<=n-1)
        {
            int a=arr[idx],b=arr[idx+1];
            flag=0;
            while(temp<=n)
            {
                if(flag)
                {
                    if(arr[temp]>b) break;
                    b=arr[temp];
                    flag=0;
                }
                else
                {
                    if(arr[temp]<a) break;
                    a=arr[temp];
                    flag=1;
                }
                temp++;
            }            
        }
        mx=max(mx,temp-idx);
        //cout<<idx<<" "<<temp<<'\n';
        idx=temp-1-flag;
    }
    cout<<mx;
}