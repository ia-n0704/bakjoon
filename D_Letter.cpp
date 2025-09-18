#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    string s[1010];
    for(int i=0;i<n;i++)
        cin>>s[i];
    int temp=0;
    int cnt=1;
    for(int i=0;i<n;i++)
    {
        temp+=s[i].length();
        if(temp>m)
        {
            temp=s[i].length();
            cnt++;
        }
        temp++;
    }
    cout<<cnt;
}