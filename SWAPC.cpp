# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
string s;
int main()
{
    fastio;
    cin>>n>>s;
    int a=0,b=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='P') a++;
        else if(s[i]=='C') b++;
    }
    int t=min(a,b);
    a=b=t;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='P' && a)
        {
            a--;
            cout<<'C';
        }
        else if(s[i]=='C' && b)
        {
            cout<<'P';
            b--;
        }
        else cout<<s[i];
    }
}