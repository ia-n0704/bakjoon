#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main()
{
    cin>>n;
    ll num=1;
    ll t=0;
    while(num<=n)
    {
        if((num&n)==0)
            t+=num;
        num*=2;
    }
    if(t==0)
    {
        cout<<1<<'\n';
        cout<<n;
    }
    else
    {
        cout<<2<<'\n';
        cout<<t<<" "<<n<<'\n';
    }
}