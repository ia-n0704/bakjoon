# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
	while(b!=0){
		ll r = a%b;
		a= b;
		b= r;
	}
	return a;
}
ll lcm(ll a, ll b){
    return a * b / gcd(a,b);
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,k;
    cin>>n>>m>>k;
    ll l=1,r=1e19;
    ll mid;
    ll g=lcm(n,m);
    while(l<=r)
    {
        mid=(l+r)/2;
        ll num=mid/n+mid/m-mid/g*2;
        if(num>k)
            r=mid-1;
        else if(num==k)
            break;
        else l=mid+1;
    }
    ll res=mid;
    ll i=0;
    while(1)
    {
        if(res-i>0)
        {
            if(((res-i)%n==0 && (res-i)%m>0) || ((res-i)%n>0 && (res-i)%m==0))
            {
                ll t=res-i;
                if(t/n+t/m-t/g*2==k)
                {
                    cout<<t;
                    return 0;
                }
            }
        }
        if(((res+i)%n==0 && (res+i)%m>0) || ((res+i)%n>0 && (res+i)%m==0))
        {
            ll t=res+i;
                if(t/n+t/m-t/g*2==k)
                {
                    cout<<t;
                    return 0;
                }
        }
        i++;
    }
}