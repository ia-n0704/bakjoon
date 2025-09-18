#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a+b<c*2)
        {
            cout<<"NO\n";
            continue;
        }        
        a%=10; b%=10;
        if((a+b)%10==(c*2)%10)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}