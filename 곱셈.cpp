#include <bits/stdc++.h>
using namespace std;
int a,b;
int main()
{
    cin>>a>>b;
    int ten=1;
    int res=0;
    while(b)
    {
        cout<<a*(b%10)<<'\n';
        res+=a*(b%10)*ten;
        ten*=10;
        b/=10;
    }
    cout<<res;
}