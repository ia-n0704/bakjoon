# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
map<string,int> M;
int main()
{
    fastio;
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n-i+1;j++)
        {
            string t=s.substr(j,i);
            M[t]++;
        }
    }
    int idx=0;
    vector<string> ans;
    int cnt=0;
    for(auto i:M)
    {
        cout<<i.first<<" "<<i.second<<'\n';
        idx++;
        if(idx==k) ans.push_back(i.first);
        if(i.second>=m) cnt++;
    }
    //cout<<ans[k-1];
}