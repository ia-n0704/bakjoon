#include <bits/stdc++.h>
using namespace std;
int main() {
    while(1)
    {
        char t;
        cin>>t;
        if(t=='#') break;
        cin.ignore();
        string s;
        getline(cin, s);
        int cnt=0;
        for(int i=0;i<s.length();i++)
            if(s[i]==t || s[i]==(char)(t-32)) cnt++;
        cout<<t<<" "<<cnt<<'\n';      
    }
}