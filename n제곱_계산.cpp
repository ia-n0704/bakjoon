# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
double _pow(double x,int a,double mod)
{
    if(a==0) return 1;
    double u=_pow(x,a/2,mod);
    u=(u*u)%mod;
    if(a%2) u=(u*x)%mod;
    return u;
}
int main()
{
    fastio;
    int t;
    cin>>t;
    int i=1;
    while(t--)
    {
        double n;
        cin>>n;
        cout<<"Case #"<<i<<": ";
        cout<<_pow(2.5,2,3);
        //cout<<(pow(double(3+sqrt(5)),n,1000.0)+pow(3-sqrt(5),n,1000)-1)%1000<'\n';
        i++;
    }
}