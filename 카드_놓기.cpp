#include <bits/stdc++.h>
using namespace std;
int n;
deque<int> q;
int arr[1000010];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int num=1;
    for(int i=n;i>=1;i--)
    {
        if(arr[i]==1)
            q.push_front(num);
        else if(arr[i]==2)
        {
            int temp=q.front();
            q.pop_front();
            q.push_front(num);
            q.push_front(temp);
        }
        else
            q.push_back(num);
        num++;
    }
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop_front();
    }
}