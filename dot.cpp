#include <bits/stdc++.h>
using namespace std;
int arr[50][50];
int brr[40][40];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin>>arr[i][j];
        
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++) cin>>brr[i][j];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int num=0;
            for(int x=i;x<=i+m;x++)
            {
                for(int y=j;y<=j+m;y++)
                {
                    num+=brr[i][j]*arr[x][y];
                    cout<<brr[i][j]<<" "<<arr[x][y]<<'\n';
                }
            }
            cout<<num<<" ";
        }
        cout<<'\n';
    }
}