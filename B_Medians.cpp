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
    if(n!=1 && (m==n || m==1))
    {
        cout<<-1<<'\n';
        return;
    }
    if(n==1)
    {
        cout<<1<<'\n'<<1<<'\n';
    }
    else
    {
        if(m%2==0)
        {
            cout<<3<<'\n';
            cout<<1<<' ';
            cout<<m<<' ';
            cout<<m+1<<'\n';            
        }
        else
        {
            cout<<3<<'\n';
            cout<<1<<' ';
            cout<<m-1<<' ';
            cout<<m+2<<'\n';   
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