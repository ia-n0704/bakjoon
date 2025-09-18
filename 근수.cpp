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
int n;
ll num[1000010];
int main()
{
    fastio;
    cin>>n>>s;
    ll cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='2')
        {
            cnt++;
            num[cnt]++;
        }
        else cnt=0;
    }
    ll res=0;
    for(int i=n-1;i>=1;i--)
        num[i]+=num[i+1];
    for(int i=1;i<=n;i++)
        res+=i*num[i];
    cout<<res;
}