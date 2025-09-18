#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin>>n;
    int s,k;
    while(n--)
    {
        cin>>s>>k;
        if(k%2)
        {
            if(s%2) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        else
        {
            if(s%(k+1)==k)
                cout<<k<<'\n';
            else if((s%(k+1))%2)
                cout<<1<<'\n';
            else cout<<0<<'\n';
        }
    }
}