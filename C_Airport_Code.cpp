# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
string s,t;
int main()
{
    fastio;
    cin>>s>>t;
    int num=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==t[num]+32)
            num++;
    }
    if(num==3 || (num==2 && t[2]=='X'))
        cout<<"Yes";
    else cout<<"No";
}