# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int t,n;
int main()
{
    fastio;
    cin>>t;
    while(t--)
    {
        priority_queue<int> pq;
        cin>>n;
        int res=0;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            pq.push(-a);
        }
        while(pq.size()>1)
        {
            int a=-pq.top();
            pq.pop();
            int b=-pq.top();
            pq.pop();
            res+=a+b;
            pq.push(-(a+b));
        }
        cout<<res<<'\n';
    }
}