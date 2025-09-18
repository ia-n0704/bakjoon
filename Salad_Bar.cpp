#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    int res=0;
    cin>>n>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='j') continue;
        int idx=i;
        int sum=0;
        int mx=0;
        while(idx<s.length())
        {
            if(s[idx]=='j')
            {
                sum--;
                if(sum<0) break;
                idx++;
                continue;
            }
            else sum++;
            mx=max(mx,sum);
            if(mx-sum<1) res=max(res,idx-i+1);
            idx++;
        }
        i=idx;
    }
    cout<<res;
}