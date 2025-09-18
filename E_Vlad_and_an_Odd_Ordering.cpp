# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,num;
void sol()
{
    cin>>n>>k;
    num=n/2;
    if(n%2) num++;
    if(k<=num)
    {
        cout<<k*2-1<<'\n';
        return;
    }
    k-=num;
    ll temp=2;
    while(1)
    {
        if(k<=(n+temp)/(temp*2))
        {
            cout<<(k*2-1)*temp<<'\n';
            return;
        }
        k-=(n+temp)/(temp*2);
        temp*=2;
    }
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