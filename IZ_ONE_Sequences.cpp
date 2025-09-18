#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    if(n<5 && k==n-1)
    {
        cout<<-1;
        return 0;
    }
    if(k==n-1)
    {
        cout<<1<<" ";
        for(int i=n-1;i>=2;i--) cout<<i<<" ";
        cout<<n<<'\n';
    }
    else if(k==n)
    {
        for(int i=n;i>=1;i--) cout<<i<<" ";
        cout<<'\n';
    }    
    else
    {
        cout<<k<<" ";
        for(int i=1;i<=n;i++)
        {
            if(i==k || i==k+2) continue;
            cout<<i<<" ";
        }
        cout<<k+2<<'\n';
    }
}