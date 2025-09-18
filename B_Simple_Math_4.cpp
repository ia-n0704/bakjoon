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
int t;
int arr[5]={6,2,4,8};
int main()
{
    fastio;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        n=arr[n%4];
        m=arr[m%4];
        k=arr[k%4];
        cout<<n<<" "<<m<<" "<<k<<'\n';
        int num;
        if(m-k<0)
            num=10+m-k;
        else num=m-k;
        if(num==0)
            cout<<n<<'\n';
        else if(num<=n)
            cout<<num%n<<'\n';
        else cout<<(10+num)%n<<'\n';
    }
}