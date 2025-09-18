# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        cin>>a;
        if(!a)
        {
            if(pq.empty()) cout<<0<<'\n';
            else
            {
                cout<<pq.top().second<<'\n';
                pq.pop();
            }
        }
        else
            pq.push({abs(a),a});
    }
}