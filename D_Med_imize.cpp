# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int arr[500010],brr[500010];
void sol()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        brr[i]=arr[i];
    }
    sort(brr+1,brr+n+1);
    int mid=brr[(n+1)/2];
    int mx=0,mxidx;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>=)
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