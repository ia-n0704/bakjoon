# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll,ll> arr[200010],brr[200010];
ll n,k;
ll temp;
void f(ll idx)
{
    if(arr[idx].second==0) return;
    ll num=arr[idx].first;
    ll i;
    for(i=idx;i<n;i++)
    {
        if(arr[i].second==0) break;
        if((i-idx+1)*(arr[i+1].first-arr[i].first)<=temp)
        {
            temp-=(i-idx+1)*(arr[i+1].first-arr[i].first);
            num=arr[i+1].first;
        }
        else break;
    }
    ll rem=temp/(n-idx+1);
    num+=rem;
    temp-=(n-idx+1)*rem;

    for(int j=idx;j<=i;j++)
    {
        arr[j].first=num;
    }
    if(temp) arr[idx].first++;
}
void sol()
{
    cin>>n>>k;
    temp=k;
    ll mid=(n+1)/2;
    for(ll i=1;i<=n;i++) cin>>arr[i].first;
    for(ll i=1;i<=n;i++) cin>>arr[i].second;
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++) brr[i]=arr[i];

    f(1);
    //cout<<temp<<'\n';
    sort(arr+1,arr+n+1);
    f(n%2?mid:mid+1);
    sort(arr+1,arr+n+1);
    //cout<<arr[n%2?mid:mid+1].first<<arr[1].first<<'\n';
    ll resa=arr[1].first+arr[n%2?mid:mid+1].first;

    temp=k;
    for(int i=1;i<=n;i++) arr[i]=brr[i];
    f(n%2?mid:mid+1);
    sort(arr+1,arr+n+1);
    f(1);
    sort(arr+1,arr+n+1);
    resa=max(resa,arr[1].first+arr[n%2?mid:mid+1].first);

    temp=k;
    for(int i=1;i<=n;i++) arr[i]=brr[i];
    f(n);
    sort(arr+1,arr+n+1);
    f(n%2?mid-1:mid);
    sort(arr+1,arr+n+1);
    ll resb=arr[n].first+arr[n%2?mid-1:mid].first;

    temp=k;
    for(int i=1;i<=n;i++) arr[i]=brr[i];
    f(n%2?mid-1:mid);
    //sort(arr+1,arr+n+1);
    f(n);
    //sort(arr+1,arr+n+1);
    resb=max(resb,arr[n].first+arr[n%2?mid-1:mid].first);
    //cout<<resa<<" "<<resb<<'\n';
    cout<<max(resa,resb)<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}