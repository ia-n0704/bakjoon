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
ll dp[100010];
ll idx[200];
int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        dp[0]=1;
        for(int i=1;i<=s.length();i++)
        {
            dp[i]=dp[i-1]*2;
            ll alpha=s[i-1];
            if(idx[alpha]) dp[i]-=dp[idx[alpha]-1];
            idx[alpha]=i;
        }cout<<dp[s.length()]<<'\n';       
        for(int i=1;i<=s.length();i++) dp[i]=0;
        for(int i=0;i<190;i++) idx[i]=0;
         
    }
}
