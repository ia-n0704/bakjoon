//try_1 : 약수를 이용한 그리디 풀이
//-> W.A

/*# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,x,y;
int main()
{
    fastio;
    cin>>n>>x>>y;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    vector<ll>v;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            v.push_back(i);
            v.push_back(n/i);
        }
    }
    v.push_back(n);
    ll res=n*x+y;
    for(auto i:v)
        res=min(res,(n/i)*x+i*x+2*y);
    cout<<res;
}*/



//sol : k제곱근에 가까운 값이 최적이라는 것을 이용한 그리디
//O(n^1/2*log n)
# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,m,k;
ll sol(double num)
{
    ll x=(ll)pow(n,1/num);
    ll cnt=0;
    while((ll)pow(x+1,cnt)*(ll)pow(x,(ll)num-cnt)<n) cnt++;
    return (x*(ll)num+cnt)*m+k*(ll)num;
}
int main()
{
    fastio;
    cin>>n>>m>>k;
    if(n==1)
    {
        cout<<-1;
        return 0;
    }
    ll res=sol(1);
    for(ll i=2;1ll<<i<=n;i++)
        res=min(res,sol(i));
    cout<<res;
}