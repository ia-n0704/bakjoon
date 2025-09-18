# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
    fastio;
    string s;
    cin>>s;
    char a='i';
    int cnt=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=a)
            cnt++;
        else 
        {
            if(a=='o') a='i';
            else a='o';
        }
    }
    if((s.length()+cnt)%2) cnt++;
    cout<<cnt;
}