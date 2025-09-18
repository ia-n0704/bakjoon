# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef long long ll;
void Y()
{
    cout<<"YES\n";
}
void N()
{
    cout<<"NO\n";
}
void sol()
{
    int n;
    int arr[100010];
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    if(arr[0]!=arr[1])
    {
        Y();
        return;
    }
    if(arr[0]==1)
    {
        N();
        return;
    }
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[0])
            continue;
        if((arr[i]%arr[0])!=0)
        {
            Y();
            return;
        }
    }
    N();
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        sol();
}