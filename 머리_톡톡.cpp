# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int ch[1000010];
int arr[100010];
int main()
{
    fastio;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        ch[arr[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        int a=arr[i];
        int cnt=0;
        for(int j=1;j*j<=a;j++)
        {
            if(a%j==0)
            {
                if(j*j==a)
                    cnt+=ch[j];
                else cnt+=ch[j]+ch[a/j];
            }
        }
        cout<<cnt-1<<'\n';
    }
}