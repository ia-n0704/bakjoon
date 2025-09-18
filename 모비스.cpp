#include <bits/stdc++.h>
using namespace std;
int m,o,b,j,t;
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='M') m=1;
        if(s[i]=='O') o=1;
        if(s[i]=='B') b=1;
        if(s[i]=='I') j=1;
        if(s[i]=='S') t=1;
    }
    if(m && o && b && j && t)
        cout<<"YES";
    else cout<<"NO";
}