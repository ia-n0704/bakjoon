#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
priority_queue<int> pq;
pair<int,int> arr[200010];
int main()
{
    fastio;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i].first>>arr[i].second;
    sort(arr+1,arr+n+1);
    pq.push(-arr[1].second);
    for(int i=2;i<=n;i++)
    {
        if(-pq.top()<=arr[i].first)
            pq.pop();
        pq.push(-arr[i].second);
    }
    cout<<pq.size();
}