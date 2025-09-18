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
int n,k;
pii arr[200010];
int cnt[200010];
unordered_map<int,int> m,re_m;
set<int> s;
int main()
{
    fastio;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].fi;
        arr[i].se=i;
        s.insert(arr[i].fi);
    }
    sort(arr+1,arr+n+1);
    arr[0].fi=-1;
    int num=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i].fi==arr[i-1].fi) continue;
        m[arr[i].fi]=++num;
        re_m[num]=arr[i].fi;
    }
    for(int i=1;i<=n;i++)
        cnt[m[arr[i].fi]]++;
    int resa;
    for(int i=0;i<=n;i++)
    {
        if(s.count(i)==0)
        {
            resa=i;
            break;
        }
    }
    for(int i=1;i<=num;i++)
    {
        if(cnt[i]<=k)
            resa=min(resa,re_m[i]);
    }
    cout<<resa<<'\n';
    int l=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i].fi<l) continue;
        int temp=arr[i].fi-l;
        if(k<temp)
        {
            cout<<l+k;
            return 0;
        }
        else
        {
            k-=temp;
            l=arr[i].fi+1;
        }
    }
    cout<<l+k;
}
