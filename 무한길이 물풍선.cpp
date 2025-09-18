#include <bits/stdc++.h>
using namespace std;
pair<int,int> arr[100010];
map<int,int> mx,my;
int main()
{
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
        mx[arr[i].first]++;
        if(mx[arr[i].first]==2) cnt++;
        my[arr[i].second]++;
        if(my[arr[i].second]==2) cnt++;
    }
    cout<<cnt;
}