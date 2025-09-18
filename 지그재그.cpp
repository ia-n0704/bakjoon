#include <bits/stdc++.h>
using namespace std;
int n;
int arr[200010];
int pos[200010];
set<int> s;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>arr[i];
        pos[arr[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        s.insert(pos[i]);
        auto idx=s.find(pos[i]);
        cout<<idx<<'\n'; 
    }
}