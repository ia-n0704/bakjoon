# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
void sol()
{
    cin>>n>>m;
    if(m==1)
        cout<<0<<'\n';
    else if(n<m) cout<<n+1<<'\n';
    else cout<<m<<'\n';
    int temp=0;
    for(int i=1;i<=n;i++)
    {
        int num=temp;
        for(int j=1;j<=m;j++)
        {
            num=(num+1)%m;
            cout<<num<<' ';
        }
        cout<<'\n';
        temp++;
        if(temp==m-1) temp=0;
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