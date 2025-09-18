#include <bits/stdc++.h>
using namespace std;
int arr[500];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=2*n;i++) arr[i]=i;
    do
    {
        cout<<n<<'\n';
        for(int i=1;i<=2*n;i++)
        {
            cout<<arr[i]<<" ";
            if(i==n) cout<<'\n';
        }
        cout<<'\n';
    }while(next_permutation(arr+1,arr+2*n+1));
}