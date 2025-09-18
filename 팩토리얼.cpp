#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x=1;
    for(long long i=1;i<=1000;i++)
    {
        x*=i;
        cout<<i<<" "<<x<<'\n';
        if(i>10) x/=10;
        if(i>30 && (i%2 || i%3)) x/=10;
        else if(i>100) x/=10;
        if(i>140 && i%3==0) x/=10;
    }
}