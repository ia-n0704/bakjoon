# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int ch[200010];
int n,m;
const ll inf=1e9;
int main()
{
    fastio;
    cin>>n>>m;
    queue<pair<int,int>> q;
    q.push({n,0});
    fill(ch,ch+200005,inf);
    while(!q.empty())
    {
        auto a=q.front();
        q.pop();
        //cout<<a.first<<" "<<a.second<<'\n';
        if(a.second>ch[m] || ch[a.first]<=a.second)
            continue;
        ch[a.first]=a.second;
        if(a.first<m)
        {
            q.push({a.first+1,a.second+1});
            q.push({a.first*2,a.second});
        }
        if(a.first>0)
            q.push({a.first-1,a.second+1});
    }
    cout<<ch[m];
}