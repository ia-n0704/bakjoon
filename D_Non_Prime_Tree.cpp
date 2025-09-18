# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> v[400010];
int ch[400010];
int prime[400010];
int ans[400010];
int num;
void dfs(int x)
{
    ans[x]=num++;
    ch[x]=1;
    for(auto i:v[x])
    {
        if(ch[i]) continue;
        while(prime[num-ans[x]]==0)
            num++;
        dfs(i);
    }
}
void sol()
{
    cin>>n;
    for(int i=1;i<=n;i++) v[i].clear();
    fill(ch,ch+n+1,0);
    for(int i=1;i<=n-1;i++)
    {
        int a,b; cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    num=1;
    dfs(1);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    prime[1]=1;
    for(int i=2;i<=400000;i++)
    {
        if(prime[i]==1)
            continue;
        for(int j=i*2;j<=400000;j+=i)
            prime[j]=1;
    }
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}