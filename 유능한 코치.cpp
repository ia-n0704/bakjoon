# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

const ll mod=99999999;
vector <int> v[100010];
int arr[100010];
int n,q;
int sqrtn;
int qone(int i, int j, ll k)
{
    int res=0;
    for(i=i;i%sqrtn && i<=j;i++)
        if(arr[i]>=k) res++;
    for(j=j;j%sqrtn!=sqrtn-1 && j>=i;j--)
        if(arr[j]>=k) res++;
    while(i<=j)
    {
        int idx=i/sqrtn;
        res+=sqrtn-(lower_bound(v[idx].begin(),v[idx].end(),k)-v[idx].begin());
        i+=sqrtn;
    }
    return res;
}
int main()
{
    fastio;
    cin>>n>>q;
    sqrtn=sqrt(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++)
        v[i/sqrtn].push_back(arr[i]);
    int num;
    if(n%sqrtn==0) num=n/sqrtn;
    else num=n/sqrtn+1;
    for(int i=0;i<num;i++)
        sort(v[i].begin(),v[i].end());
    ll temp=0,cnt=1;
    while(q--)
    {
        int i,j;
        ll k;
        cin>>i>>j>>k;
        k=(temp*cnt+k)%mod+1;
        int res=qone(i-1,j-1,k);
        cout<<(j-i+1)-res<<'\n';
        temp=(j-i+1)-res;
        cnt++;
    }
}