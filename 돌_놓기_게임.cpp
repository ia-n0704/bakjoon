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
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<ll> vll;
ll n;
ll arr[400010],brr[400010];
ll num[400010],c[400010];
int main()
{
    fastio;
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>brr[i];
    for(ll i=1;i<=n;i++)
        cin>>c[i];
    ll st=1;
    for(ll i=1;i<=n;i++)
    {
        if(brr[i]!=0)
        {
            st=i;
            break;
        }
    }
    ll idx=1;
    for(ll i=st;i<=n;i++)
    {
        arr[idx]=brr[i];
        num[idx]=c[i];
        idx++;
    }
    for(ll i=1;i<=st;i++)
    {
        arr[idx]=brr[i];
        num[idx]=c[i];
        idx++;
    }
    ll l=1;
    ll sum=0;
    ll resa=0,resb=0;
    vector<ll> v;
    for(ll i=2;i<=n+1;i++)
    {
        if(arr[l]!=arr[i] && arr[i]!=0)
        {
            ll mid=(i+l-1)/2;
            ll temp=0;
            if((i-l+1)%2) temp=1;
            for(ll j=l+1;j<=mid;j++)
            {
                if(arr[l]==1) resa+=num[j];
                else resb+=num[j];
            }
            for(ll j=mid+temp+1;j<=i;j++)
            {
                if(arr[i]==1) resa+=num[j];
                else resb+=num[j];
            }
            sum=0;
            if((i-l+1)%2)
                v.push_back(num[mid+1]);
            l=i;
        }
        else if(arr[l]==arr[i] && arr[i]!=0)
        {
            sum+=num[i];
            if(arr[i]==1) resa+=sum;
            else resb+=sum;
            sum=0;
            l=i;
        }
        else
            sum+=num[i];
        //cout<<resa<<" "<<resb<<" "<<l<<'\n';
    }
    sort(all(v));
    reverse(all(v));
    for(ll i=0;i<v.size();i++)
    {
        if(i%2) resb+=v[i];
        else resa+=v[i];
    }
    cout<<resa<<" "<<resb;
}
