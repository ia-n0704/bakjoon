# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
void sol()
{
    string a,b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    int idx=0;
    for(;idx<a.length();idx++)
        if(a[idx]<b[idx]) break;
    for(int i=idx+1;i<a.length();i++)
        if(a[i]<b[i]) swap(a[i],b[i]);
    cout<<a<<'\n'<<b<<'\n'; 
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