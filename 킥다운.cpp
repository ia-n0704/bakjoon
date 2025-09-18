#include<bits/stdc++.h>
using namespace std;
string s,t;
int main()
{
    cin>>s>>t;
    int res=1e9;
    int x=t.length();
    for(int i=-x;i<=(int)s.length();i++)
    {
        int a=i;
        int flag=0;
        int st=min(0,i);
        int en=max(s.length(),i+t.length());
        for(int j=0;j<t.length();j++)
        {
            if(a<s.length() && a>=0 && t[j]==s[a] && t[j]=='2')
            {
                flag=1;
                break;
            }
            a++;
        }
        if(!flag)
            res=min(res,en-st);
    }
    cout<<res;
}