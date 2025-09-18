#include <bits/stdc++.h>
using namespace std;
int t;
int num[1000];
int main()
{
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++)
            num[s[i]]++;
        vector<int> v;
        for(int i='a';i<='z';i++)
            if(num[i]) v.push_back(num[i]);
        int res=0;
        sort(v.begin(),v.end());
        for(int i=0;i<(int)v.size()-2;i++)
            res+=v[i];
        cout<<res<<'\n';
        for(int i='a';i<='z';i++) num[i]=0;
    }
}