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
int n,k;
ll arr[5010];
void sol()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    if(k==1)
    {
        ll res=arr[1]+arr[n];
        for(int j=2;j<n;j++)
            res=max(res,arr[j]+max(arr[1],arr[n]));
        cout<<res<<'\n';
        return;
    }
    ll mx=0;
    for(int i=1;i<=n;i++)
    {
        ll mx1=0,mx1_idx;
        ll mx2=0,mx2_idx;
        for(int j=1;j<i;j++)
        {
            if(mx1<arr[j])
            {
                mx1=arr[j];
                mx1_idx=j;
            }
        }
        for(int j=i+1;j<=n;j++)
        {
            if(mx2<arr[j])
            {
                mx2=arr[j];
                mx2_idx=j;
            }
        }
        vector<ll> v;
        for(int j=1;j<=n;j++)
        {
            if(j==i || j==mx1_idx || j==mx2_idx) continue;
            v.push_back(arr[j]);
        }
        sort(v.begin(),v.end());
        ll res=mx1+mx2;
        for(int j=3;j<=k;j++)
        {
            res+=v.back();
            v.pop_back();
        }
        res+=arr[i];
        mx=max(mx,res);
    }
    cout<<mx<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}