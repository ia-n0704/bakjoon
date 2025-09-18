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
int main()
{
    fastio;
    cin>>n;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    if(n%2)
    {
        cout<<-1;
        return 0;
    }
    cout<<n<<" ";
    for(int i=n-1;i>1;i-=2)
        cout<<i<<" "<<n-i+1<<" ";
    cout<<1;
}
