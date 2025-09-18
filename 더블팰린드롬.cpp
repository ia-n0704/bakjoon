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
string s[10010];
int main()
{
    fastio;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        int flag=0;
        for(int i=0;i<s.length()/2;i++)
        {
            if(s[i]!=s[s.length()-i-1])
                flag=1;
        }
        if(flag==0) cnt++;
    }
    cout<<cnt*(cnt-1);
}