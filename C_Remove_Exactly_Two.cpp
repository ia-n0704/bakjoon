# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
vector<int> v[200010];
int ch[200010];
int num[200010];
void dfs(int x,int flag)
{
    ch[x]=1;
    int cnt=flag;
    for(auto i:v[x])
    {
        if(ch[i]) continue;
        cnt++;
        dfs(i,1);
    }
    num[x]=cnt;
}
void sol()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0);
    pii mx={0,0};
    for(int i=1;i<=n;i++)
    {
        if(mx.fi<num[i])
            mx={num[i],i};
    }
    vector<int> check;
    check.push_back(mx.se);
    for(auto i:v[mx.se])
    {
        if(num[i]==mx.fi)
            check.push_back(i);
    }
    int res=0;
    for(auto i:check)
    {
        fill(ch,ch+n+1,0);
        fill(num,num+n+1,0);
        ch[i]=1;
        for(int i=1;i<=n;i++)
            if(ch[i]==0) dfs(i,0);
        int mx2=0;
        for(int i=1;i<=n;i++)
            if(mx2<num[i]) mx2=num[i];
        res=max(res,mx.fi+mx2-1);
    }
    cout<<res<<'\n';
    for(int i=1;i<=n;i++)
    {
        ch[i]=0;
        num[i]=0;
        v[i].clear();
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}