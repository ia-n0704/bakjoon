#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int cnt[1000],cnt2[1000];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=0;j<s.length();j++)
            cnt[s[j]-'A']++;
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>s;
        int flag=0;
        fill(cnt2,cnt2+999,0);
        for(int j=0;j<s.length();j++)
            cnt2[s[j]-'A']++;
        for(int j='A'-'A';j<='Z'-'A';j++)
            if(cnt[j]<cnt2[j]) flag=1;
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
}