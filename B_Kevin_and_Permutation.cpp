# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int res[100010];
void sol()
{
   cin>>n>>k;
   fill(res+1,res+n+1,0);
   int cnt=1;
   for(int i=k;i<=n;i+=k) 
        res[i]=cnt++;
    for(int i=1;i<=n;i++)
    {
        if(res[i]==0)
            res[i]=cnt++;
    }
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
    cout<<'\n';
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