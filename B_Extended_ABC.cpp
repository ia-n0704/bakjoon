# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    int a=-1,b=-1,c=-1;
    int i;
    for(i=0;i<s.length();i++)
    {
        if(s[i]=='A')
        {
            if(b!=-1 || c!=-1) break;
            if(a!=i-1 && a!=-1)
                break;
            a=i;
        }
        else if(s[i]=='B')
        {
            if(c!=-1) break;
            if(b!=i-1 && b!=-1)
                break;
            b=i;
        }
        else if(s[i]=='C')
        {
            if(c!=i-1 && c!=-1)
                break;
            c=i;
        }
    }
    if(i==s.length())
        cout<<"Yes";
    else cout<<"No";
}