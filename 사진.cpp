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
int cnt[100010];
int ch[100010];
vector<int> v[100010];
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        cnt[b]++;
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<=n;i++)
        if(cnt[i]==0) pq.push(i);
    while(!pq.empty())
    {
        auto a=pq.top();
        pq.pop();
        if(ch[a]) continue;
        ch[a]=1;
        cout<<a<<" ";
        for(auto i:v[a])
        {
            cnt[i]--;
            if(cnt[i]==0) pq.push(i);
        }
    }
}