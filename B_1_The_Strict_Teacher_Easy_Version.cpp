# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q;
int arr[500010];
void sol()
{
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++) cin>>arr[i];
    sort(arr+1,arr+m+1);
    while(q--)
    {
        int a;
        cin>>a;
        int high=upper_bound(arr+1,arr+m+1,a)-arr;
        int low=high-1;
        if(low==0)
            cout<<arr[high]-1;
        else if(high==m+1)
        {
            if(arr[low]==a) cout<<0;
            else cout<<n-arr[low];
        }
        else
        {
            if(arr[low]==a) cout<<0;
            else
            {
                int mid=(arr[low]+arr[high])/2;
                cout<<mid-arr[low];
            }
        }
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