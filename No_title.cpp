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
int arr[1010];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cout<<"? "<<1<<" * "<<i+1<<endl;
        cin>>arr[i+1];
    }
    cout<<"? "<<2<<" * "<<3<<endl;
    cin>>arr[1];
    cout<<"! ";
    for(int i=1;i<=n;i++)
    {
        cout<<"+ ";
    }
}