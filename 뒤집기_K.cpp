#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <ll X,ll MOD> struct Hashing
{
    vector<ll> H,B;
    void build(const vector<ll> &v2)
    {
        H.resize(v2.size()+1);
        B.resize(v2.size()+1);
        B[0]=1;
        for(int i=1;i<=v2.size();i++)
        {
            B[i]=(B[i-1]*X)%MOD;
            H[i]=(H[i-1]*X+v2[i-1])%MOD;
        }
    }
    ll get(int s,int e)
    {
        s++;
        e++;
        ll res=(H[e]-H[s-1]*B[e-s+1])%MOD;
        return (res+MOD)%MOD;
    }
};
int n,k;
ll arr[400010];
vector<ll> v;
Hashing<200000,1'000'000'007> T;
bool compare(ll a,ll b)
{
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(T.get(a,a+mid-1)==T.get(b,b+mid-1))
            l=mid+1;
        else r=mid-1;
    }
    if(r==n-1) return 0;
    else return v[a+r]<v[b+r];
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k; k--;
    for(int i=n-1;i>=0;i--) cin>>arr[i];
    for(int i=n;i<n*2;i++) arr[i]=arr[i-n];
    for(int i=0;i<n*2;i++) v.push_back(arr[i]);
    T.build(v);
    vector<ll> num;
    for(int i=1;i<n;i++) num.push_back(i);
    sort(num.begin(),num.end(),compare);
    for(int i=0;i<n;i++) cout<<v[num[k]+i]<<" ";
}