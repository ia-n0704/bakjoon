# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void sol()
{
    string s,t;
    cin>>s>>t;
    int flag=0;
    if(s.length()<t.length()) swap(s,t);
    ll res=0;
    for(int i=0;i<s.length()-t.length();i++)
    {
        flag=1;
        res+=s[i]-'0';
    }
    for(int i=0;i<t.length();i++)
    {
        int j=i+s.length()-t.length();
        if(flag) res+=9;
        else
        {
            if(s[j]!=t[i])
                flag=1;
            res+=abs((s[j]-'0')-(t[i]-'0'));
        }
    }
    cout<<res<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}