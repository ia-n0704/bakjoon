# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int arr[300010];
void sol()
{
    int n;
    int st;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i==0) st=arr[i];
    }
    int cnt=0;
    int res=n;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==st) cnt++;
        else 
        {
            res=min(res,cnt);
            cnt=0;
        }
    }
    res=min(res,cnt);
    if(res==n) cout<<-1<<'\n';
    else
        cout<<res<<'\n';
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