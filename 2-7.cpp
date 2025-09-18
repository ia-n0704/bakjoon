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
int n;
string s[40010];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    sort(s+1,s+n+1);
    vector<char> res;
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            for(int j=0;j<s[i].length();j++)
                res.push_back(s[i][j]);
            res.push_back('P');
            continue;
        }
        int cnt=0;
        for(int j=0;j<min(s[i-1].length(),s[i].length());j++)
        {
            if(s[i-1][j]!=s[i][j]) break;
            cnt++;
        }
        for(int j=0;j<s[i-1].length()-cnt;j++)
            res.push_back('-');
        for(int j=cnt;j<s[i].length();j++)
            res.push_back(s[i][j]);
        res.push_back('P');
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<'\n';
}
