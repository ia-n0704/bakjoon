# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
void sol()
{
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    int idx=0;
    for(int i=0;i<t.length();i++)
    {
        if(s[idx]==t[i])
        {
            idx++;
        }
    }
    cout<<idx<<'\n';
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