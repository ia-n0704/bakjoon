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
ll n,k;
string a,b;
int main()
{
    fastio;
    cin>>n>>k;
    cin>>a>>b;
    ll res=0;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    for(int i=0;i<n;i++)
    {
        if(!pq.empty() && pq.top().fi<i)
        {
            res+=abs(pq.top().se);
            pq.push({pq.top().fi+k,pq.top().se});
            pq.pop();
        }
        if(a[i]!=b[i])
        {
            int flag;
            if(a[i]=='1') flag=1;
            else flag=-1;
            if(pq.empty() || abs(pq.top().se)<abs(pq.top().se+flag))    //반대 부호라는거임 ㅇㅇ
            {
                if(pq.empty() || pq.top().fi!=i)
                    pq.push({i,flag});
                else
                {
                    auto a=pq.top();
                    pq.pop();
                    pq.push({i,a.se+flag});
                }
            }
            else
            {
                auto a=pq.top();
                pq.pop();
                if(a.se+flag!=0)
                    pq.push({a.fi,a.se+flag});
            }
        }
        //cout<<res<<'\n';
    }
    cout<<res;
}
