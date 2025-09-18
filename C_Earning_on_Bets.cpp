# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll arr[55];
ll res[55];
void sol()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    ll sum=0;
    ll mx=0;
    ll mx2=0;
    ll mn=100;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(mx<arr[i])
        {
            mx2=mx;
            mx=arr[i];
        }
        else if(mx2<arr[i])
            mx2=arr[i];
        mn=min(mn,arr[i]);
    }
    ll num=(ll)mn*1000000000/(ll)mx;
    sum=0;
    for(int i=0;i<n;i++)
    {
        res[i]=num/arr[i];
        if(num%arr[i]) res[i]++;
        sum+=res[i];
    }
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(res[i]*arr[i]<=sum) flag=1;
    }
    if(flag) cout<<-1<<'\n';
    else
    {
        for(int i=0;i<n;i++) cout<<res[i]<<" ";
        cout<<'\n';
    }
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