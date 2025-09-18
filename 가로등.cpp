# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll l,n,k;
ll arr[300010];
map<ll,ll> m;
int main()
{
    fastio;
    cin>>l>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int num=0;
    while(1)
    {
        ll cnt=0;
        for(int i=1;i<=n;i++)
        {
            ll le=arr[i]-num,r=arr[i]+num;
            if(le>=0 && m[le]==0)
                m[le]=1,cnt++;   
            if(r<=l && m[r]==0)
                m[r]=1,cnt++;
        }
        if(k<=cnt)
        {
            for(int i=0;i<k;i++) cout<<num<<'\n';
            break;
        }
        else
        {
            k-=cnt;
            for(int i=0;i<cnt;i++) cout<<num<<'\n';
        }
        num++;
    }
}