# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[200010];
void sol()
{
    ll n,k;
    cin>>n>>k;
    ll num=0;
    for(int i=1;i<=n;i++) 
    {
        arr[i]=i;
        num+=abs(i-(n-i+1));
    }
    if(k%2 || k>num)
    {
        cout<<"No\n";
        return;
    }
    int i=1;
    while(k)
    {
        if(n-i+1>=i+k/2)
        {
            swap(arr[i],arr[i+k/2]);
            break;
        }
        else 
        {
            swap(arr[i],arr[n-i+1]);
            k-=(abs(arr[n-i+1]-arr[i]))*2;
        }
        i++;
    }
    cout<<"Yes\n";
    for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
    cout<<'\n';
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