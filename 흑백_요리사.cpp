/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    ll res=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ll a;
        cin>>a;
        res=res*a/__gcd(res,a);
    } 
    cout<<res*2;       
}*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    ll res=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ll a;
        cin>>a;
        ll g;
        for(int i=min(res,a);i>=1;i--)
            if(res%i==0 && a%i==0)
            {
                g=i;
                break;
            }
        res=res*a/g;
    } 
    cout<<res*2;       
}