# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int arr[200010];
void sol()
{
    int n,m;
    cin>>n>>m;
    int st=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]==m) st=i;
    }
    int l=1,r=n+1;
    while(r-l!=1)
    {
        int mid=(l+r)/2;
        if(arr[mid]<=m)
            l=mid;
        else r=mid;
    }
    cout<<1<<'\n';
    cout<<st<<" "<<l<<'\n';
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