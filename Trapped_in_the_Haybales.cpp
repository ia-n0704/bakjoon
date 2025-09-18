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
typedef vector<pii> vpii;
typedef vector<pll> vpll;
int n;
pii arr[100010],brr[100010];
set<int> s;
vpii v;

int f(pii a)
{
    return a.se-a.fi;
}
bool compare(pii a,pii b)
{
    return f(a)>f(b);
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].se>>arr[i].fi;
        brr[i]=arr[i];
    }
    sort(arr+1,arr+n+1);
    sort(brr+1,brr+n+1,compare);
    int idx=1;
    for(int i=1;i<=n;i++)
    {

        while(idx<=n && -arr[i].fi<=f(brr[idx]))
        {
            s.insert(brr[idx].fi);
            idx++;
        }
        auto temp=s.upper_bound(arr[i].fi+arr[i].se);
        if(temp!=s.begin()) temp--;
        //cout<<*temp<<'\n';
        if(arr[i].fi!=*temp)
            v.push_back({arr[i].fi,*temp});
    }
    int l=0;
    int res=0;
    for(auto i:v)
    {
        //cout<<i.fi<<" "<<i.se<<'\n';
        res+=max(0,i.se-max(l,i.fi));
        l=max(l,i.se);
        //cout<<res<<'\n';
    }
    cout<<res;
}
