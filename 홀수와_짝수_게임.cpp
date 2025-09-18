#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a=0;
        cin>>n;
        for(int i=1,c;i<=n;i++)
        {
            cin>>c;
            if(c%2) a++;
        }
        int b=n-a;
        if(a==b || !(max(a,b)%2)) cout<<"heeda0528\n";
        else cout<<"amsminn\n";
    }
}