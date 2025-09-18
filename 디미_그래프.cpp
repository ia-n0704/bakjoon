# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin,(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n,m;
vector<int> v[100010];
int ch[100010];
set<pair<int,int>> s;
int flag;
int cycle;
void dfs(int x,int t)
{
    //cout<<x<<'\n';
    ch[x]=1;
    for(auto i:v[x])
    {
        if(s.count({x,i})) continue;
        s.insert({x,i});
        s.insert({i,x});
        if(ch[i])
        {
            //cout<<"| "<<i<<'\n';
            if(cycle==0)
                cycle=1;
            else flag=1;
            continue;
        }
        dfs(i,x);
    }
}
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int one=0,three=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i].size()!=2)
        {
            if(v[i].size()>=4 || v[i].size()==0)
            {
                cout<<"NO";
                return 0;
            }
            if(v[i].size()==1)
            {
                if(one==0)
                    one=1;
                else
                {
                    cout<<"NO";
                    return 0;
                }
            }
            if(v[i].size()==3)
            {
                if(three==0)
                    three=1;
                else
                {
                    cout<<"NO";
                    return 0;
                }
            }
        }
    }
    if(three==0 || one==0)
    {
        cout<<"NO";
        return 0;
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        if(ch[i]==0) flag=1;
    if(flag) cout<<"NO";
    else cout<<"YES";
}
