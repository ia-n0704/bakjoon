# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[300010],brr[300010];
int idxa[300010],idxb[300010];
void sol()
{
    int n,flag=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) cin>>brr[i];
    for(int i=1;i<=n;i++) if(arr[i]!=brr[i]) flag=1;
    if(!flag)
    {
        cout<<"Bob\n";
        return;
    }
    flag=0;
    reverse(arr+1,arr+n+1);
    for(int i=1;i<=n;i++) if(arr[i]!=brr[i]) flag=1;
    if(!flag)
    {
        cout<<"Bob\n";
        return;
    }
    cout<<"Alice\n";
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