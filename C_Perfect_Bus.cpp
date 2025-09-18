# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
long long arr[200010];
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    long long mn=1e16;
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        mn=min(mn,sum);
    }
    long long st=max((long long)0,-mn);
    cout<<st+sum;
}