#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        if(s[s.length()-1]=='0')
            cout<<"E\n";
        else cout<<"B\n";
    }
}