#include<bits/stdc++.h>
using namespace std;
int n;
int arr[200010];
deque<int> v[5];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        v[arr[i]%3].push_back(arr[i]);
    }
    int a=(int)v[0].size();
    int b=(int)v[1].size();
    int c=(int)v[2].size();
    if((!a && b && c) || (a-1>b+c))
    {
        cout<<-1;
        return 0;
    }
    while(a>1)
    {
        cout<<v[0][0]<<" ";
        v[0].pop_front();
        if(b)
        {
            b--;
            cout<<v[1][0]<<" ";
            v[1].pop_front();
        }
        else
        {
            c--;
            cout<<v[2][0]<<" ";
            v[2].pop_front();
        }
        a--;
    }
    while(b)
    {
        b--;
        cout<<v[1][0]<<" ";
        v[1].pop_front();
    }
    if(a)
    {
        a--;
        cout<<v[0][0]<<" ";
        v[0].pop_front();        
    }
    while(c)
    {
        c--;
        cout<<v[2][0]<<" ";
        v[2].pop_front();
    }
}