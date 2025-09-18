#include <bits/stdc++.h>
using namespace std;
int arr[100010],res[100010];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==i)
        {
            cnt++;
            if(i==1)
                res[i]=n;
            else res[i]=i-1;
        }
        else res[i]=arr[i];
    }
    cout<<cnt<<'\n';
    for(int i=1;i<=n;i++)
        cout<<res[i]<<" ";
}