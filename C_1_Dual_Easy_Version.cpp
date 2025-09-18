# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int arr[2000];
void sol()
{
    int n;
    cin<<n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=2;i<=n;i++)
    {
        pair<int,int> mx={-21,-1},mn={21,-1};
        for(int i=1;i<=n;i++)
        {
            if(mx.first<arr[i])
            {
                mx.first=arr[i];
                mx.second=i;
            }
            if(mn.first>arr[i])
            {
                mn.first=arr[i];
                mn.second=i;
            }
        }        
        if(arr[i-1]>arr[i])
        {
            int res1=0,res2=0;
            if(mx.first>0)
            {
                 
            }
        }
    }
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