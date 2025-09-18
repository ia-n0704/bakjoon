#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n;
pii arr[100010];
int ch[100010];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++)
    {
        if(arr[i].second<=arr[i].first)
            ch[i]=1;
    }
    int num=arr[n].first;
    int temp=arr[n].first;
    for(int i=n;i>=1;i--)
    {
        num+=temp-arr[i].first;
        temp=arr[i].first;
        //cout<<num<<' ';
        if(ch[i]) continue;
        num+=max(0,arr[i].second-num);
        //cout<<num<<"\n";
    }
    num+=arr[1].first;
    cout<<num;
}