#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int arr[5];
    fill(arr,arr+4,b);
    if(a>=5) arr[0]=b-500;
    if(a>=10) arr[1]=b-b*10/100;
    if(a>=15) arr[2]=b-2000;
    if(a>=20) arr[3]=b-b*25/100;
    sort(arr,arr+4);
    cout<<max(0,arr[0]);
}