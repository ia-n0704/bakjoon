#include <bits/stdc++.h>
using namespace std;
int arr[100][100];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%1d",&arr[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
}