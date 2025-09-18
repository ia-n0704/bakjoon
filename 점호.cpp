# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,k;
int arr[100010];
int a,b,cnt;
int main()
{
    fastio;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<=k;i++)
    {
        if(arr[i]==1) a++;
        else b++;
    }
    int r=k;
    while(r<n)
    {
        if(!a)
        {
            b--;
            r++;
            if(arr[r]==1) a++;
            else b++;
        }
        else if(!b)
        {
            a--;
            r++;
            if(arr[r]==1) a++;
            else b++;
        }
        else
        {
            a--;
            b--;
            for(int i=r+1;i<=min(n,r+2);i++)
            {
                if(arr[i]==1) a++;
                else b++;
            }
            r+=2;
        }
        cnt++;
    }
    cout<<cnt+max(a,b);
}