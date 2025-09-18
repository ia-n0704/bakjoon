# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int ans[200010];
void sol()
{
    int n,k;
    cin>>n>>k;
    int l=1,r=n;
    for(int i=1;i<=n;i++)
    {
        if(ans[i]) continue;
        for(int j=i;j<=n;j+=k)
        {
            if(i%2)
            {
                ans[j]=l;
                l++;
            }
            else
            {
                ans[j]=r;
                r--;
            }            
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<'\n';
    fill(ans,ans+n+1,0);
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