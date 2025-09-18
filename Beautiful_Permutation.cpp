# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
int res[1000010];
int main()
{
    fastio;
    cin>>n;
    fill(res,res+n,-1);
    if(n%4>1) 
    {
        cout<<"NO";
        return 0;
    }  
    int a=n-1,b=n-1;
    int temp=-1;
    while(a)
    {
        if(a==n/2) a--;
        res[b]=b+temp*a;
        b+=temp*a;
        a--;
        temp=-temp;
    }
    res[b]=n-1;
    cout<<"YES\n";
    for(int i=0;i<n;i++) 
    {
        if(res[i]==-1) cout<<i<<" ";
        else cout<<res[i]<<" ";
    }
}