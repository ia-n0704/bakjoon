#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[1000];
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(arr[i]==arr[j])
            {
                int num=j-i;
                if((int)sqrt(num)*(int)sqrt(num)!=num) cout<<1; 
                else cout<<arr[i]<<" ";
            }
        }
    }

}