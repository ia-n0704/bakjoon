#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    if(n%2)
    {
        for(int i=n;i>=1;i-=2)
            cout<<i<<" ";
        cout<<"1 ";
        for(int i=2;i<=n-1;i+=2)
            cout<<i<<" "<<i+1<<" "<<i<<" ";
    }
    else
    {
        for(int i=n;i>=4;i-=2)
            cout<<i<<" ";
        cout<<"1 2 1 2 ";
        for(int i=3;i<=n-1;i+=2)
            cout<<i<<" "<<i+1<<" "<<i<<" ";
    }
}