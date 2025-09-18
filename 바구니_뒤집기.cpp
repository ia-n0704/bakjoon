#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[200010],brr[200010];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) arr[i]=i;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        for(int j=1;j<=n;j++)
            brr[j]=arr[j];
        int idx=b;
        for(int j=a;j<=b;j++)
        {
            arr[j]=brr[idx--];
        }
    }
    for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
}