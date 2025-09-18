# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[200010];
void sol()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int flag=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]%2) flag=1;
        else cnt++;
    }
    if(flag)
    {
        cout<<cnt<<'\n';
        return;
    }
    int res=(int)1e9;
    for(int i=1;i<=n;i++)
    {
        int num=0;
        while(1)
        {
            if(arr[i]%2) break;
            num++;
            arr[i]/=2;
        }
        res=min(res,num);
    }
    cout<<res+cnt-1<<'\n';
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