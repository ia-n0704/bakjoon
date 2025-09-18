# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
void sol()
{
    int n,k;
    cin>>n>>k;
    int num=n*4-2;
    if(k<=n*2)
    {
        if(k%2)
            cout<<k/2+1<<'\n';
        else
            cout<<k/2<<'\n';
        return;
    }
    else
    {
        if(k<=num-2)
        {
            if(k%2)
                cout<<k/2+1<<'\n';
            else
                cout<<k/2<<'\n';
        }
        else
            cout<<(num-2)/2+k-(num-2)<<'\n';
        return;
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