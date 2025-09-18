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
ll n;
ll m;
pair<string,ll> arr[200010];
ll v[200010];
ll mx[200010];
ll total;
int main()
{
    fastio;
    cin>>n;
    cin>>m;
    for(int i=1;i<=m;i++)
        cin>>arr[i].fi>>arr[i].se;
    fill(mx+1,mx+m+1,0);
    for(int i=1;i<=m;i++)
    {
        ll num=0;
        for(int j=0;j<arr[i].fi.length();j++)
        {
            if(arr[i].fi[j]=='F') num++;
            else num--;
            mx[i]=max(mx[i],num);
        }
        total+=num*arr[i].se;
        v[i]=num;
    }
    //cout<<total;
    if(total<0)
    {
        cout<<"-1";
        return 0;
    }
    ll temp=0;
    ll res=0;
    for(int i=1;i<=m;i++)
    {
        //cout<<temp<<" "<<mx[i]<<" "<<arr[i].se<<'\n';
        res=max(res,temp+mx[i]+max(0ll,v[i])*(arr[i].se-1));
        temp+=v[i]*arr[i].se;
        
    }
    //cout<<res<<'\n';
    cout<<max(0ll,res-total-1ll);
}
