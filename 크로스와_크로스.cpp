#include <bits/stdc++.h>
using namespace std;
int n,arr[2024],mex[2024];
int main()
{
    cin>>n;
    arr[1]=arr[2]=arr[3]=1;
    for(int i=4;i<=n;i++)
    {
        fill(mex,mex+2023,0);
        for(int j=i-3;j>=(i-4)/2;j--)
        {
            mex[arr[j]^arr[max(0,i-j-5)]]=1;
        }
        for(int j=0;j<=2000;j++)
        {
            if(mex[j]==0) 
            {
                arr[i]=j;
                break;
            }
        }
    }
    if(arr[n]) cout<<1;
    else cout<<2;
}