#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int flag=0;
    int a=n;
    while(a)
    {
        if(a%10==7) flag=1;
        a/=10;
    }
    if(flag)
    {
        if(n%7) cout<<2;
        else cout<<3;
    }
    else
    {
        if(n%7) cout<<0;
        else cout<<1;
    }
}