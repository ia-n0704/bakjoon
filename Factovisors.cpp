# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n,m;
int main()
{
    fastio;
    while(2 == scanf("%d%d\n",&n,&m))
    {
        if(m==0)
        {
            cout<<"0 does not divide "<<n<<"!\n";
            continue;
        }
        ll mm=m;
        vector<pll> v;
        for(ll i=2;i*i<=mm;i++)
        {
            ll cnt=0;
            while(m%i==0)
            {
                m/=i;
                cnt++;
            }
            if(cnt) v.push_back({i,cnt});
        }
        if(m>1) v.push_back({m,1});
        int flag=0;
        for(auto i:v)
        {
            ll num=i.first;
            ll cnt=i.second;
            ll temp=num;
            ll cnt2=0;
            while(temp<=n)
            {
                cnt2+=n/temp;
                temp*=num;
            }
            if(cnt2<cnt) flag=1;
        }      
        cout<<mm;
        if(flag==0) cout<<" divides ";
        else cout<<" does not divide ";
        cout<<n<<"!\n";
    }
}