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
pii arr[1000010];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i].se>>arr[i].fi;
    sort(arr+1,arr+n+1);
    reverse(arr+1,arr+n+1);
    int r=arr[1].fi;
    for(int i=1;i<=n;i++)
    {
        r=min(r,arr[i].fi);
        r-=arr[i].se;
    }
    cout<<r;
}
