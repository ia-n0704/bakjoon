# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int t;
string s;
int main()
{
    fastio;
    cin>>t;
    while(t--)
    {
        cin>>s;
        int n=sqrt(s.length());
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n*n;j+=n)
                cout<<s[j];
        }
        cout<<'\n';
    }
}