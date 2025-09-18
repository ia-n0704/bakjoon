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
int arr[100010];
int idx[100010];
int brr[100010];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        idx[arr[i]]=i;
    }
    int num=n;
    while(num>1)
    {
        if(idx[num]<idx[num-1])
        {
            swap(idx[num],idx[num-1]);
            num-=2;
        }
        else
            num--;
    }
    for(int i=1;i<=n;i++)
        brr[idx[i]]=i;
    for(int i=1;i<=n;i++) cout<<brr[i]<<" ";
}