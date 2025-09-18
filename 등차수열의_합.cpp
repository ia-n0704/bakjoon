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
ll arr[100010];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int flag=0;
    for(int i=3;i<=n;i++)
    {
        if(arr[i-1]-arr[i-2]!=arr[i]-arr[i-1])
            flag=1;
    }
    if(flag)
        cout<<"NO";
    else 
    {
        cout<<"YES\n";
        for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
        cout<<'\n';
        for(int i=1;i<=n;i++) cout<<0<<" ";
    }
}