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
    int flag=0;
    for(int i=0;i<s.length()/2;i++)
    {
        if(s[i]!=s[s.length()-i-1]) flag=1;
    }
    if(flag)
    {
        cout<<s.length();
        return 0;
    }
    for(int i=s.length()-1;i>0;i--)
    {
        if(s[i]!=s[i-1])
        {
            flag=1;
            break;
        }
    }
    if(flag) cout<<s.length()-1;
    else cout<<-1;
}