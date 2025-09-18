# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
struct T
{
    ll num;
    ll l,d;
};
bool operator < (T a,T b)
{
    return a.num>b.num;
}
ll n;
priority_queue<T> pq;
int main()
{
    fastio;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        pq.push({a+b,a,b});
    }
    ll num=0;
    int cnt=0;
    priority_queue<ll> temp;
    while(!pq.empty())
    {
        T a=pq.top();
        pq.pop();
        if(num>a.l)
        {
            ll c=temp.top();
            if(num-c<a.l && c>a.d)
            {
                temp.pop();
                temp.push(a.d);
                num=num-c+a.d;
            }
        }
        else 
        {
            cnt++;
            num+=a.d;
            temp.push(a.d);
        }
    }
    cout<<cnt;
}