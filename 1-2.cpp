# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
ll n,q;
ll fen[8010][8010];
void update(ll x,ll y,ll num)
{
    ll temp=y;
    while(x<=n)
    {
        while(temp<=n)
        {
            fen[x][temp]+=num;
            temp+=(temp&-temp);
        }
        temp=y;
        x+=(x&-x);
    }
}
ll query(ll x,ll y)
{
    ll temp=y;
    ll res=0;
    while(x>0)
    {
        while(temp>0)
        {
            res+=fen[x][temp];
            temp-=(temp&-temp);            
        }
        temp=y;
        x-=(x&-x);
    }
    return res;
}
int main()
{
    fastio;
    cin>>n>>q;
    while(q--)
    {
        ll a;
        cin>>a;
        if(a==1)
        {
            ll b,c,d;
            cin>>b>>c>>d;
            update(b,c,d);
        }
        else
        {
            ll x1,x2,y1,y2;
            cin>>x1>>y1>>x2>>y2;
            cout<<query(x2,y2)-(query(x2,y1-1)+query(x1-1,y2)-query(x1-1,y1-1))<<'\n';
        }
    }
}
