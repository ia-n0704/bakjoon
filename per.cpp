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
int arr[1000010];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    prev_permutation(arr+1,arr+n+1);
    for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
    cout<<'\n';
    next_permutation(arr+1,arr+n+1);
    next_permutation(arr+1,arr+n+1);
    for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
    cout<<'\n';
}