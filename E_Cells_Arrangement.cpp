# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
void sol()
{
    int n;
    cin>>n;
    if(n==2)
    {
        cout<<"1 1\n";
        cout<<"1 2\n";
    }
    else if(n==3)
    {
        cout<<"2 1\n";
        cout<<"2 3\n";
        cout<<"3 1\n";
    }
    else
    {
        cout<<"1 1\n";
        cout<<"1 2\n";
        cout<<"4 2\n";
        for(int i=4;i<=n;i++) cout<<i<<" "<<i<<'\n';
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