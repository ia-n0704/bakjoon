# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int arr[10101];
void sol()
{
    int n,m;
    cin>>n>>m;
    if(n>m) swap(n,m);
    for(int i=0;i<n*m;i++)
        cin>>arr[i];
    sort(arr,arr+n*m);
    cout<<max((n*m-n)*(arr[n*m-1]-arr[0])+(n-1)*(arr[n*m-1]-arr[1]),(n*m-n)*(arr[n*m-1]-arr[0])+(n-1)*(arr[n*m-2]-arr[0]))<<'\n';
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

//20 