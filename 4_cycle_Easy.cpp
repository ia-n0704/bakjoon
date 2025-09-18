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
vector<int> v[1010];
int res;
int num[1010];
int temp;
void dfs(int x,int cnt)
{
    for(auto i:v[x])
    {
        if(i<temp) continue;
        if(num[i])
        {
            if(cnt-num[i]==3) res++;
            continue;
        }
        num[i]=cnt+1;
        dfs(i,cnt+1);
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
    for(int i=1;i<=n;i++)
    {
        temp=i;
        num[i]=1;
        dfs(i,1);
        fill(num+1,num+n+1,0);
    }
    cout<<res;
}