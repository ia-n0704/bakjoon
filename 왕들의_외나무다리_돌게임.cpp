#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100010];
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    int a=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        a^=(arr[i]-2);
    }
    string s;
    cin>>s;
    if(s=="Whiteking")
    {
        if(a==0) cout<<"Blackking";
        else cout<<"Whiteking";
    }
    else
    {
        if(a==0) cout<<"Whiteking";
        else cout<<"Blackking";
    }
}