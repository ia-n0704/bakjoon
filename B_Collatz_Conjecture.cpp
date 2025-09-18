# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    int num=m-n%m;
    while(n!=1 && k-num>=0)
    {
        //cout<<n<<" "<<k<<"\n";
        k-=num;
        n+=num;
        while(n%m==0) n/=m;
        num=m-n%m;
    }
    //cout<<n<<" "<<k<<'\n';
    if(n==1)
    {
        if((1+k%(m-1))==m) cout<<1<<'\n';
        else 
            cout<<k%(m-1)+1<<'\n';
    }
    else cout<<n+k<<'\n';
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