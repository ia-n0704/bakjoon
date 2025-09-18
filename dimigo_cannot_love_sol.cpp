#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[100010];
int flag;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(m>0) m-=(arr[i]-1);
        if(arr[i]==0)
            flag=1;        
    }
    if(flag || m>0)
        cout<<"OUT";
    else cout<<"DIMI";
}