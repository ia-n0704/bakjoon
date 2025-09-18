# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll m,tempa,tempb;
int main()
{
    fastio;
    cin>>tempa>>tempb>>m;
    while(m--)
    {
        ll a=tempa,b=tempb;
        ll c;
        cin>>c;
        while(c--)
        {
            swap(a,b);
            b=abs(a-b);
            ll num;
            if(b==0)
            {
                num=c/3;
            }
            else if(c/3<a/(b*2))
                num=c/3;
            else
            {
                num=a/(b*2);
            } 
            c-=num*3;
            a-=num*b*2;
        }
        cout<<a<<'\n';
    }
}