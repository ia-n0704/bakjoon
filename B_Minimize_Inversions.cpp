# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
pair<int,int> arr[200010];
void sol()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i].first;
    for(int i=0;i<n;i++)
        cin>>arr[i].second;
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
        cout<<arr[i].first<<" ";
    cout<<'\n';
    for(int i=0;i<n;i++)
        cout<<arr[i].second<<" ";
    cout<<'\n';
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