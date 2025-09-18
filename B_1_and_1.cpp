# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll arr[200010];
void sol()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int flag=0;
    ll sum=arr[1];
    for(int i=2;i<=n;i++)
    {
        if(arr[i-1]>arr[i])
        {
            if(i==n)
            {
                //cout<<arr[i-1]<<" "<<arr[i]<<'\n';
                flag=1;
                break;
            }
            arr[i+1]-=arr[i-1]-arr[i];
            arr[i]=arr[i-1];
            sum+=arr[i];
        }
        else
        {
            ll num=(sum+arr[i])/i;
            ll temp=num*i+(sum+arr[i])%i;
            arr[i]=num+(sum+arr[i])%i;
            sum=temp;
        }
        //cout<<arr[i]<<" ";
    }
    if(flag) cout<<"No\n";
    else cout<<"Yes\n";
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