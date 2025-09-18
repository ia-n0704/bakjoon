# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void sol()
{
    cin>>n;
    if(n%2)
    {
        if(n>=27)
        {
            cout<<1<<" ";
            for(int i=2;i<=5;i++)
                cout<<i<<" "<<i<<" ";
            cout<<1<<" 13 ";
            for(int i=6;i<=12;i++)
                cout<<i<<" "<<i<<" ";
            int num=14;
            cout<<"1 13 ";
            for(int i=1;i<=(n-27)/2;i++)
            {
                cout<<num<<" "<<num++<<" ";
            }
            cout<<'\n';
        }
        else cout<<-1<<'\n';
    }
    else
    {
        int num=1;
        for(int i=1;i<=n/2;i++)
            cout<<num<<" "<<num++<<" ";
        cout<<'\n';
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