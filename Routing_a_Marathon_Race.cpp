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
int arr[50];
vector<int> v[50];
int ch[50];
int cnt[50];
int res=1e9;
void dfs(int x,int co)
{
    if(cnt[x]==0) co+=arr[x];
    ch[x]=1;
    vector<int> v2;
    for(auto i:v[x])
    {
        if(ch[i]) continue;
        if(cnt[i]==0) co+=arr[i];
        cnt[i]++;
        v2.push_back(i);
    }
    //cout<<x<<" "<<co<<'\n';
    if(x==n)
        res=min(res,co);
    else
    {
        for(auto i:v[x])
        {
            if(cnt[i]>=2 || ch[i]) continue;
            dfs(i,co);
        }
    }
    ch[x]=0;
    for(auto i:v2) cnt[i]--;
}
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0);
    cout<<res;
}
