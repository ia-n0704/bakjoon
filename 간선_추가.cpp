#include <bits/stdc++.h>
using namespace std;
int arr[1024][1024];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a][b]++;
        arr[b][a]++;
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=1;j<=n;j++)
        {
            sum+=arr[i][j];
        }
        if(sum%2)
        {
            cout<<"NO";
            break;
        }
    }
    cout<<"YES";
}