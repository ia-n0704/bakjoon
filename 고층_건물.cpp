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
ll arr[100];
int mx=0;
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int j=1;j<i;j++)
        {
            int flag=0;
            double a=(double)(arr[i]-arr[j])/(i-j);
            double b=arr[j]-(double)(arr[i]-arr[j])/(i-j)*j;
            for(int r=j;r<i;r++)
            {
                if(j==r)
                    continue;
                if(a*r+b<=(double)arr[r])
                    flag=1;
            }
            if(flag==0) cnt++;
            
        }

        for(int j=i+1;j<=n;j++)
        {
            int flag=0;
            double a=(double)(arr[j]-arr[i])/(j-i);
            double b=arr[i]-(double)(arr[j]-arr[i])/(j-i)*i;
            for(int r=i+1;r<j;r++)
            {
                if(j==r)
                    continue;
                if(a*r+b<=(double)arr[r])
                    flag=1;
            }
            if(flag==0) cnt++;
        }
        mx=max(mx,cnt);
    }
    cout<<mx;
}