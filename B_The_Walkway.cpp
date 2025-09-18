# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,d;
int arr[100010];
void sol()
{
    cin>>n>>m>>d;
    arr[0]=1;
    for(int i=1;i<=m;i++) cin>>arr[i];
    int cnt=1;
    for(int i=1;i<=m;i++)
    {
        if(arr[i]!=arr[i-1])
            cnt+=(arr[i]-arr[i-1]-1)/d;
        cnt++;
    }
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        if(arr[i]-arr[i-2]<=d) 
        {
            cnt--;
            ans=i-1;
            break;
        }
    }
    if(n-arr[m])
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