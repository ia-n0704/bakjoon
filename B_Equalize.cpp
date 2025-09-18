# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
void sol()
{
    int n;
    int arr[200010];
    set<int> s;
    cin>>n;
    int i;
    int m=n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        if(s.count(arr[i]))
        {
            i--;
            n--;
            continue;
        }
        s.insert(arr[i]);
    }
    sort(arr,arr+n);
    int mx=0;
    for(int i=0;i<n;i++)
    {
        int num=arr[i]+m;
        int idx=upper_bound(arr,arr+n,num-1)-arr;
        mx=max(mx,idx-i);
    }
    cout<<mx<<'\n';
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