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
int n,q;
ll arr[100010];
int main()
{
    fastio;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    while(q--)
    {
        int c;
        int l,r,d,x;
        cin>>c;
        if(c==1)
        {
            cin>>l>>r>>d>>x;
            for(int i=l;i<=r;i+=d)
                arr[i]+=(ll)x;
        }
        else
        {
            cin>>l>>r>>d;
            ll res=0;
            for(int i=l;i<=r;i+=d)
                res+=arr[i];
            cout<<res<<'\n';
        }
    }
}
