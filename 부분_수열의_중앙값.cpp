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
map<int,int> m;
int main()
{
    fastio;
    cin>>n>>k;
    int idx;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]==k) idx=i;
    }
    int cnt=0;
    for(int i=idx;i<=n;i++)
    {
        if(i!=idx)
        {
            if(arr[i]>k) cnt++;
            else cnt--;
        }
        m[cnt]++;
    }
    cnt=0;
    ll res=0;
    for(int i=idx;i>=1;i--)
    {
        if(i!=idx)
        {
            if(arr[i]>k) cnt--;
            else cnt++;
        }
        res+=(ll)m[cnt];
    }
    cout<<res;
}