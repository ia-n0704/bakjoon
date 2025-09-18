# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
pair<int,int> arr[100010];
ll two[100010];
void cal()
{
    two[0]=1;
    for(int i=1;i<=100000;i++)
        two[i]=(two[i-1]*2)%mod;
}
void sol()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i].first;
    for(int i=1;i<=n;i++) cin>>arr[i].second;
    for(int i=1;i<=n;i++)
    {
        cout<<two[arr[i].second]<<'\n';
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t=1;
    cal();
    while(t--)
    {
        sol();
    }
}