#include <bits/stdc++.h>
using namespace std;
int n;
string s,t;
pair<int,int> arr[300],brr[300];
int main()
{
    cin>>n>>s>>t;
    for(int i=0;i<n;i++)
    {
        int a=s[i];
        int b=t[i];
        if(i%2)
        {
            arr[a].first++;
            brr[b].first++;            
        }
        else
        {
            arr[a].second++;
            brr[b].second++;
        }
    }
    int flag=0;
    for(int i='a';i<='z';i++)
    {
        if(arr[i].first!=brr[i].first || arr[i].second!=brr[i].second) flag=1;
    }
    if(!flag) cout<<"TAK";
    else cout<<"NIE";
}