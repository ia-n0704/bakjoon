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
map<string,int> m;
string s[100010];
int main()
{
    fastio;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    int l=0,r=n;
    int temp=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        int idx=1;
        int flag=0;
        for(int i=1;i<=mid;i++)
        {
            m[s[i]]++;
            if(m[s[i]]>4)
                flag=1;
        }
        for(int i=mid+1;i<=n;i++)
        {
            m[s[idx++]]--;
            m[s[i]]++;
            if(m[s[i]]>4)
                flag=1;
        }
        if(flag)
        {
            temp=1;
            r=mid-1;
        }
        else l=mid+1;
        m.clear();
    }
    if(temp==0) cout<<-1;
    else cout<<l;
}
