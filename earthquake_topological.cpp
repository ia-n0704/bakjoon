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
int n;
int num[200010],deg[200010];
int ch[200010];
vector<int> v[200010];
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
        deg[a]++;
        deg[b]++;
    }
    for(int i=1;i<=n;i++)
        cin>>num[i];
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=1;i<=n;i++)
        if(deg[i]==1) pq.push({num[i],i});
    while(pq.size()>1)
    {
        auto a=pq.top();
        ch[a.se]=1;
        pq.pop();
        for(auto i:v[a.se])
        {
            if(ch[i]) continue;
            deg[i]--;
            num[i]=max(num[i],num[a.se]+1);
            if(deg[i]==1) pq.push({num[i],i});
        }
    }
    cout<<num[pq.top().se];
}
