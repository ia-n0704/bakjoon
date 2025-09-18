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
ll dp[1010][1010];
const ll mod=10007;
int main()
{
    fastio;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        dp[i][i]=1;
        if(i==s.length()-1) continue;
        if(s[i]==s[i+1]) dp[i][i+1]=3;
        else dp[i][i+1]=2;
    }
    for(int i=2;i<s.length();i++)
    {
        for(int j=0;j<s.length()-i;j++)
        {
            int l=j,r=j+i;
            dp[l][r]=dp[l+1][r]+dp[l][r-1]-dp[l+1][r-1]+mod;
            if(s[l]==s[r]) dp[l][r]+=dp[l+1][r-1]+1;
            dp[l][r]%=mod;
        }
    }
    cout<<dp[0][s.length()-1];
}

//splay_tree, link_cut_tree