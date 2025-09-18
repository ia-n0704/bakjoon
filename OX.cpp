#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    string s;
    cin>>s;
    ll res=0;
    ll num=1;
    for(ll i=0;i<s.length();i++)
    {
        if(s[i]=='O')
        {
            res+=num;
            res%=(ll)(1e9+7);
        }
        num*=2;
        num%=(ll)(1e9+7);
    }
    cout<<res;
}