# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
vector<int> v[300010];
int n;
int P[300010];
int ch[300010];
int main()
{
    fastio;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int a;
        cin>>a;
        v[i].push_back(a);
        v[a].push_back(i);
    }
    for(int i=1;i<=n;i++) cin>>P[i];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    ch[1]=1;
    pq.push({P[1],1});
    for(int i=1;i<=n;i++)
    {
        auto a=pq.top();
        cout<<a.first<<'\n';
        pq.pop();
        ch[a.second]=1;.
        for(auto j:v[a.second])
        {
            if(ch[j]==0)
            {
                pq.push({P[j],j});
            }
        }
    }
}