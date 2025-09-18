# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
int arr[200010],brr[200010];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n-1;i++) cin>>brr[i];
    sort(brr+1,brr+n);
    int idx=n-1;
    int flag=0;
    int ans;
    for(int i=n;i>=1;i--)
    {
        if(idx==0) break;
        while(arr[i]>brr[idx])
        {
            if(flag==0)
            {
                ans=arr[i--];
                flag=1;
            }
            else
            {
                cout<<-1;
                return 0;
            }
        }
        idx--;
    }
    if(flag==0) ans=arr[1];
    cout<<ans;
}