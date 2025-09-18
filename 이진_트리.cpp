# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin,(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
struct T
{
    ll res,sz,l,r;
}arr[100010];
const ll mod=1e9+7;
int main()
{
    fastio;
    cin>>n;
    arr[0]={1,1,1,1};
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[i].res=(arr[a].res+arr[b].res+arr[a].r*arr[b].sz+arr[a].sz*arr[b].l-1)%mod;
        arr[i].sz=(arr[a].sz+arr[b].sz)%mod;
        arr[i].l=(arr[a].l+arr[b].l+arr[b].sz-1)%mod;
        arr[i].r=(arr[b].r+arr[a].r+arr[a].sz-1)%mod;
        cout<<arr[i].res<<'\n';
    }
}
