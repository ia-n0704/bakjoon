#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long ans=n;
    n--;
    int i=1;
    while(i<=n)
    {
        int temp=n/(n/i);
        ans+=(n/i)*(temp-i+1);
        i=temp+1;
    }
    cout<<ans;
}