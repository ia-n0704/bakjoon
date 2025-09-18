# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int arr[100010];
void sol()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int num=1;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==num)
        {
            num++;
            continue;
        }
        cnt++;
    }
    cout<<cnt/k+(bool)(cnt%k)<<'\n';
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