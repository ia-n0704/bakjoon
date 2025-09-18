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
int arr[101];
int a,b;
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    sort(arr+1,arr+n+1);
    cin>>a>>b;
    int mn;
    int num=2e9;
    int numa=a;
    if(numa%2==0) numa++;
    int numb=b;
    if(numb%2==0) numb--;
    for(int i=1;i<=n;i++)
        num=min(num,abs(numa-arr[i]));
    mn=num;
    int res=numa;
    num=2e9;
    for(int i=1;i<=n;i++)
        num=min(num,abs(numb-arr[i]));
    if(mn<num) 
    {
        res=numb;
        mn=num;
    }

    for(int i=1;i<n;i++)
    {
        int s=(arr[i]+arr[i+1])/2;
        for(auto temp:{s-1,s,s+1})
        {
            if(temp%2==0 || temp<=a || temp>=b) continue;
            int t=2e9;
            for(int i=1;i<=n;i++)
                t=min(t,abs(temp-arr[i]));
            if(mn<t)
            {
                res=temp;
                mn=t;
            }            
        }
    }
    cout<<res;
}