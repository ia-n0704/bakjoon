# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[200010];
void sol()
{
    int n;
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n-1;i++) mx=max(mx,arr[i]);
    cout<<arr[n]+mx<<'\n';;
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