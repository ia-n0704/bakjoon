# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
const ll mod=998244353;
ll arr[30];
ll f[500010];
ll ans;
ll n;
ll m[500010];
vector<int> v;
ll sum,s;
void dp(int i,int k,int e) {
    if (i==e) {
        if (e==n && k<=s)
            ans=(ans+m[s-k])%mod;
        else
            m[k]=(m[k]+1)%mod;
        return;
    }
    dp(i+1,k,e);
    dp(i+1,k+v[i],e);
}
void sol()
{
    for(int i=0;i<26;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
        if(arr[i]) v.push_back(arr[i]);
    }
    sort(all(v));
    n=v.size();
    s=sum/2;
    dp(0,0,n/2);
    dp(n/2,0,n);
    cout<<ans<<'\n';
    ll temp=sum/2;
    if(sum%2) temp++;
    cout<<((ans%mod)*f[temp])%mod<<'\n';

    for(int i=0;i<=sum;i++) m[i]=0;
    sum=ans=0;
    v.clear();
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    f[0]=f[1]=1;
    for(int i=2;i<=500000;i++) f[i]=(f[i-1]*i)%mod;
    while(t--)
    {
        sol();
    }
}
