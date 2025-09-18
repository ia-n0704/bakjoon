#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b;
    while(1)
    {
        cin>>a>>b;
        if(a<b) swap(a,b);
        if(!a && !b) break;
        ll cnt=0;
        while(1)
        {
            if(a%b==0 || a/b>=2)
            {
                if(cnt%2)
                    cout<<"B";
                else cout<<"A";
                cout<<" wins\n";
                break;
            }
            ll r=a-b;
            a=b;
            b=r;
            cnt++;
        }
    }
}