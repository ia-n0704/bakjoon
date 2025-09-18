#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int> arr[200020];
bool compare(pair<int,int> p1,pair<int,int> p2)
{
    return p1.first>p2.first;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i].first>>arr[i].second;
    sort(arr,arr+n,compare);
    int idx=0;
    int res=0;
    priority_queue<int> pq;
    for(int i=n;i>=1;i--)
    {
        while(arr[idx].first==i)
        {
            pq.push(arr[idx].second);
            idx++;
        }
        if(!pq.empty())
        {
            res+=pq.top();
            pq.pop();
        }
    }
    cout<<res;
}
