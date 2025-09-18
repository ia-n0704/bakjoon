# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int arr[101];
int idx[101];
void sol()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        idx[arr[i]]=i;
    }
    int cnt=0;
    while(cnt<=n)
    {
        int num=0;
        for(int i=1;i<=n;i++)
        {
            if(idx[i]!=i)
            {
                num=i;
                break;
            }
        }
        if(num==0) break;
        swap(idx[num])
    }
    if(idx[n]==n) cout<<"YES\n";
    else cout<<"NO\n";
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