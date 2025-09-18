# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int arr[200010];
int brr[200010];
void sol()
{
    cin>>n;
    int mn=n+1;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n-1;i++) brr[i]=arr[i]+arr[i+1];
    for(int i=n;i>=1;i--)
    {
        int num=n-i;
        int big=arr[i];
        int idx=upper_bound(brr+1,brr+n,big)-brr;
        num+=idx-1;
        mn=min(mn,num);
        //cout<<idx<<" ";
    }
    cout<<mn<<'\n';
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