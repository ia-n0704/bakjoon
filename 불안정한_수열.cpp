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
int arr[300010];
int main()
{
    fastio;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        arr[i]=arr[i]%2;
    }
    int temp=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=temp)
        {
            temp=arr[i];
            cnt++;
        }
    }
    temp=1;
    int mx=cnt;
    cnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=temp)
        {
            temp=arr[i];
            cnt++;
        }
    }
    mx=max(mx,cnt);
    cout<<mx;
}