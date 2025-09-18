#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,string> a,pair<int,string> b)
{
    if(a.first<b.first) return 1;
    return 0;
}
pair<int,string> arr[100010];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i].first>>arr[i].second;
    stable_sort(arr+1,arr+n+1,compare);
    for(int i=1;i<=n;i++) cout<<arr[i].first<<" "<<arr[i].second<<'\n';
}