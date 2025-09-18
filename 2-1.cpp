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
string s,t;
int n,m;
int f[1000010];
void init()
{
    int idx=0;
    for(int i=1;i<t.length();i++)
    {
        while(idx>0 && t[i]!=t[idx])
            idx=f[idx-1];
        if(t[i]==t[idx])
            f[i]=++idx;
    }
}
vector<int> sol()
{
    int idx=0;
    vector<int> res;
    for(int i=0;i<s.length();i++)
    {
        while(idx>0 && s[i]!=t[idx])
            idx=f[idx-1];
        if(s[i]==t[idx])
        {
            if(idx==t.length()-1)
            {
                res.push_back(i-t.length()+2);
                idx=f[idx];
            }
            else
                ++idx;
        }
    }
    return res;
}
int main()
{Q
    fastio;
    vector<int> res;
    cin>>n;
    cin.ignore();
    getline(cin,s);
    cin>>m;
    cin.ignore();
    getline(cin,t);
    init();
    res=sol();
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
}
