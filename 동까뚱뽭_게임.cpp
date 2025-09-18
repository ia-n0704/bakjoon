# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
vector<int> v[100010];
int ch[100010];
int ans[100010];
void go(int x)
{
    int flag=0;
    ch[x]=1;
    for(auto i:v[x])
    {
        if(ch[i]==0)
        {
            go(i);
            if(ans[i]==0) flag=1;
        }
    }
    if(flag) ans[x]=1;
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    go(1);
    for(int i=1;i<=n;i++)
    {
        if(ans[i]) cout<<"donggggas\n";
        else cout<<"uppercut\n";
    }
}