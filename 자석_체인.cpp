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
    int n;
    string s;
    cin>>n>>s;
    for(int i=1;i<2*n;i++)
    {
        if(s[i]==s[i-1])
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}