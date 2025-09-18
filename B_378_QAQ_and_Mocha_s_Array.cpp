# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int arr[200010];
void sol()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+n+1);
    int i;
    for(i=1;i<=n;i++)
    {
        if(arr[i]%arr[1])
            break;
    }
    int idx=i;
    for(i=idx;i<=n;i++)
        if(arr[i]%arr[idx] && arr[i]%arr[1]) break;
    if(i==n+1)
        cout<<"Yes\n";
    else cout<<"No\n";
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