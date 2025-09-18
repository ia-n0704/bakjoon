# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int arr[200010];
void sol()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+n+1);
    int res;
    int num=0;
    int l=1,r=2e9;
    while(l<=r)
    {
        int mid=(l+r)/2;
        res=0;
        for(int i=1;i<=n;i++)
        {
            res+=min(mid,arr[i]);
            if(res>=k) break;
        }
        if(res>=k) r=mid-1;
        else l=mid+1;
    }
    int num2=0;
    for(int i=1;i<=n;i++)
    {
        num+=min(arr[i]+1,l);
        num2+=min(arr[i],l);
        if(num2>=k)
        {
            num-=num2-k;
            break;
        }
    }
    cout<<num<<'\n';
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