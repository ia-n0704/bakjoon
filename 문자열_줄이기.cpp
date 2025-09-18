# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m;
string s;
int ch[300010];
vector<pair<int,int>> v;
int main()
{
    fastio;
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<s.length();i++)
        v.push_back({s[i]-'0',i});
    sort(v.begin(),v.end());
    for(int i=0;i<m;i++)
        ch[v[i].second]=1;
    for(int i=0;i<n;i++)
        if(ch[i]==0) cout<<s[i];
}