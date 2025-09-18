# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
string s;
int dp[100010];
int idx[100];
int main()
{
    fastio;
    cin>>s;
    dp[0]=1;
    for(int i=1;i<=s.length();i++)
    {
        dp[i]=dp[i-1]*2;
        int alpha=s[i-1]-'a';
        if(idx[alpha]) dp[i]-=dp[idx[alpha]-1];
        idx[alpha]=i;
    }
    cout<<dp[s.length()]-1;
}
