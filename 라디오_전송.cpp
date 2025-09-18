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
int pi[1000010];
void piset()
{
    int j=0;
    for(int i=1;i<s.length();i++)
    {
        while(j>0 && s[i]!=s[j])
            j=pi[j-1];
        if(s[i]==s[j])
            pi[i]=++j;
    }
}
int main()
{
    fastio;
    cin>>n>>s;
    piset();
    cout<<n-pi[n-1];
}