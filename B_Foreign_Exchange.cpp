# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[200010];
ll s[200010],t[200010];
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n-1;i++)
        cin>>s[i]>>t[i];
    for(int i=0;i<n-1;i++)
    {
        ll num=arr[i]/s[i];
        arr[i+1]+=num*t[i];
    }
    cout<<arr[n-1];
}