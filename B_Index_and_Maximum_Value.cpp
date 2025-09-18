# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int arr[100010];
void sol()
{
    cin>>n>>m;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        mx=max(mx,arr[i]);
    }
    for(int i=1;i<=m;i++)
    {
        char c;
        int l,r;
        cin>>c>>l>>r;
        if(l<=mx && r>=mx)
        {
            if(c=='-') mx--;
            else mx++;
        }
        cout<<mx<<" ";
    }
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