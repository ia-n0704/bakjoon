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
int arr[100010];
int idx_a[100010];
int brr[100010];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        idx_a[arr[i]]=i;
    }
    for(int i=1;i<=n;i++)
        cin>>brr[i];
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==brr[i])
            continue;
        cnt++;
        swap(arr[i],arr[idx_a[brr[i]]]);
        swap(idx_a[arr[i]],idx_a[arr[idx_a[brr[i]]]]);
    }
    if(cnt%2) cout<<"Impossible";
    else cout<<"Possible";
}