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
int ch[10][200010];
int arr[200010];
bool compare(int a,int b)
{
    int resa=0,resb=0;
    for(int i=1;i<=5;i++)
    {
        if(ch[i][a]<ch[i][b]) resa++;
        else resb++;
    }
    return resa>resb;
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) arr[i]=i;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int a;
            cin>>a;
            ch[i][a]=j;
        }
    }
    sort(arr+1,arr+n+1,compare);
    for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
}