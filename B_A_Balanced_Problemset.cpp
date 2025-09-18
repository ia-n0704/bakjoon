# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
void sol()
{
    int n,k;
    int ans=0;
    cin>>n>>k;
    int sqrtn=sqrt(n);
    for(int i=1;i<=sqrtn;i++)
    {
        if(i>n/k) break;
        if(n%i==0)
        {
            ans=max(ans,i);
            if(n/i<=n/k)
                ans=max(ans,n/i);
        }
    }
    cout<<ans<<'\n';
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