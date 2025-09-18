#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    int a=k,b=k;
    cin>>s;
    vector<int> v;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')
        {
            if(a>0)
                a--;
            else v.push_back(0);
        }
        else
        {
            if(b>0) b--;
            else v.push_back(1);
        }
    }
    for(int i=0;i<v.size()-a-b;i++)
        cout<<v[i];
}