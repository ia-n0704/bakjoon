# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void sol()
{
    int n;
    ll num=pow(2,31)-1;
    cin>>n;
    ll arr[200010];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int l=0,r=n-1;
    ll res=0;
    while(l<r)
    {
        //cout<<num<<'\n';
        if(arr[l]+arr[r]>num)
            r--;
        else if(arr[l]+arr[r]<num)
            l++;
        else
        {
            l++;
            r--;
            res++;
        }
    }
    cout<<n-res<<'\n';
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