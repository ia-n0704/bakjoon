#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    if(s.length()==2)
        cout<<(s[1]-'0')+(s[0]-'0');
    else if(s.length()==4)
        cout<<20;
    else
    {
        if(s[1]=='0')
            cout<<(s[0]-'0')*10+(s[2]-'0');
        else cout<<(s[0]-'0')+10*(s[1]-'0');
    }
}