#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        pq.push(a);
    }
    int a,b;
    int res=0;
    while(1)
    {
        a=pq.top();
        pq.pop();
        if(pq.empty()) break;
        b=pq.top();
        pq.pop();
        pq.push(a+b);
        res+=a+b;
    }
    cout<<res;
}