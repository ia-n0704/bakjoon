# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
set<int> s;
int n;
int arr[2000010];
ll ch[2000010];
int main()
{
    fastio;
    cin>>n;
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        ch[arr[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j*j<=arr[i];j++)
        {
            if(arr[i]%j==0)
            {
                if(j*j==arr[i])
                    res+=ch[j];
                else res+=ch[j]+ch[arr[i]/j];
            }
        }
    }
    cout<<res-n;
}