# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
ll l,r;
void sol()
{
    cin>>l>>r;
    ll a=l,b=r;
    ll num=1;
    while(num<=b)
        num*=2;
    num/=2;
    ll res=0;
    if(l&num)
    {
        int flag=0;
        for(ll i=num;i>0;i/=2)
        {
            if(flag)
            {
                if((l&i)==0 && (r&i)==0)
                    
            }
            else if((l&i)!=(r&i))
            {
                flag=1;
                res+=i;

            }
        }
    }
    cout<<res<<" "<<l<<" "<<r<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}