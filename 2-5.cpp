# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
const ll mod=200003;
int n;
string s;
ll h[200010];
int main()
{
    fastio;
    cin>>n;
    cin>>s;
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        vector<vector<int>> v(mod);
        ll pp=1;
        ll p=26;
        for(int i=1;i<=mid;i++)
            pp=pp*p%mod;
        ll num=0;
        for(int i=0;i<mid;i++)
            num=(num*p+s[i])%mod;
        v[num].push_back(0);
        int flag=0;
        for(int i=1;i<n-mid+1;i++)
        {
            num=(num*p%mod-pp*s[i-1]%mod+s[i+mid-1]+mod)%mod;
            //cout<<num<<'\n';
            for(auto j:v[num])
            {
                if(!strncmp(&s[j],&s[i],mid))
                {
                    flag=1;
                    break;
                }
            }
            v[num].push_back(i);
        }
        if(flag) l=mid+1;
        else r=mid-1;
    }
    if(r<=0) r=0;
    cout<<r;
}
