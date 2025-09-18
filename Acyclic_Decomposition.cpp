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
int ch[100010];
vector<int> ans1,ans2;
vector<int> v[100010];
int cnt[100010];
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a>b) ans1.push_back(i);
        else ans2.push_back(i);
        v[a].push_back(b);
        cnt[b]++;
    }
    queue<int> q;
    vector<int> l;
    for(int i=1;i<=n;i++)
        if(cnt[i]==0) q.push(i);
    while(!q.empty())
    {
        int a=q.front();
        l.push_back(a);
        q.pop();
        for(auto i:v[a])
        {
            cnt[i]--;
            if(cnt[i]==0) q.push(i);
        }
    }
    if(l.size()==n)
    {
        cout<<1<<'\n';
        cout<<m<<" ";
        for(int i=1;i<=m;i++) cout<<i<<" ";
    }
    else
    {
        cout<<2<<'\n';
        cout<<ans1.size()<<" ";
        for(auto i:ans1) cout<<i<<" ";
        cout<<'\n';
        cout<<ans2.size()<<" ";
        for(auto i:ans2) cout<<i<<" ";        
    }
}