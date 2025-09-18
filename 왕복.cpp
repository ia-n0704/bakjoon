#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll arr[200010];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        if(k-arr[i]<=0)
        {
            if(i==n)
            {
                cout<<n;
                return 0;
            }
            else
            {
                cout<<i+1;
                return 0;
            }
        }
        k-=arr[i];
    }
    for(int i=n;i>=1;i--)
    {
        if(k-arr[i]<=0)
        {
            if(k==arr[i])
            {
                cout<<i-1;
                return 0;
            }
            cout<<i;
            return 0;
        }
        k-=arr[i];
    }
}