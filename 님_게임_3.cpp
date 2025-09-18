#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int arr[1010];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int a=0;
        for(int j=0;j<n;j++)
            if(i!=j) a^=arr[j];
        for(int j=0;j<arr[i];j++)
            if((a^j)==0) cnt++;
    }
    cout<<cnt;
}