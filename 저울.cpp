#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1010];
int main()
{
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int idx=1;
    int r=0;
    for(int i=0;i<n;i++)
    {
        int nxl=arr[i];
        int nxr=r+arr[i];
        if(nxl<=r+1)
            r=nxr;
        else
        {
            cout<<r+1;
            return 0;
        }
    }
    cout<<r+1;
}