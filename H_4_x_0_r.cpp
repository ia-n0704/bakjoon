# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
string s;
int main()
{
    fastio;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='a') cout<<4;
        else if(s[i]=='e') cout<<3;
        else if(s[i]=='i') cout<<1;
        else if(s[i]=='o') cout<<0;
        else if(s[i]=='s') cout<<5;
        else cout<<s[i];
    }   
}